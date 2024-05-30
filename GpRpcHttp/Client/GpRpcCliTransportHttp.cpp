#include "GpRpcCliTransportHttp.hpp"

#include <GpCore2/GpUtils/Streams/GpByteWriterStorageByteArray.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Body/GpHttpBodyPayloadFixed.hpp>

namespace GPlatform {

GpRpcCliTransportHttp::GpRpcCliTransportHttp
(
    GpReflectSerializer::SP aSerializer,
    GpHttpClient::SP        aHttpClient
) noexcept:
iSerializer{std::move(aSerializer)},
iHttpClient{std::move(aHttpClient)}
{
}

GpRpcCliTransportHttp::~GpRpcCliTransportHttp (void) noexcept
{
}

GpReflectObject::SP GpRpcCliTransportHttp::ProcessRQ
(
    const GpUrl&                                    aUrl,
    std::optional<GpReflectObject::C::Ref::CVal>    aRq,
    const std::vector<const GpReflectModel*>&       aRsTypeStructVariants,
    std::optional<SerializeRqFnT>                   aBeforeSerializeRqFn,
    std::optional<SerializeRqFnT>                   aAfterSerializeRqFn,
    std::optional<ProcessRqRsFnT>                   aBeforeProcessFn,
    std::optional<ProcessRqRsFnT>                   aAfterProcessFn
)
{
    const GpReflectSerializer& serializer = iSerializer.V();

    // RQ/RS
    GpHttpResponse::SP httpRs;

    {
        // Serialize RQ to body
        GpBytesArray body;
        if (aRq.has_value())
        {
            const GpReflectObject& rqDesc = aRq.value().get();

            // TODO: move to factory
            body.resize(1024);

            GpByteWriterStorageByteArray    bodyStorage(body);
            GpByteWriter                    bodyWriter(bodyStorage);
            SerializeRqFnRes                serializeRqFnRes = SerializeRqFnRes::CONTINUE;

            if (aBeforeSerializeRqFn.has_value())
            {
                serializeRqFnRes = aBeforeSerializeRqFn.value()(bodyWriter);
            }

            if (serializeRqFnRes == SerializeRqFnRes::CONTINUE)
            {
                serializer.FromObject(rqDesc, bodyWriter);
            }

            if (aAfterSerializeRqFn.has_value())
            {
                aAfterSerializeRqFn.value()(bodyWriter);
            }

            bodyWriter.OnEnd();
        }

        // Prepate HTTP RQ
        GpHttpHeaders       rqHeaders;
        GpHttpRequest::SP   httpRq = MakeSP<GpHttpRequest>
        (
            GpHttpRequestNoBodyDesc
            {
                GpHttpVersion::HTTP_1_1,
                GpHttpRequestType::POST,
                aUrl,
                rqHeaders
            },
            MakeSP<GpHttpBodyPayloadFixed>(std::move(body))
        );

        if (aBeforeProcessFn.has_value())
        {
            auto rq = GpAny{GpHttpRequest::SP(httpRq)};
            aBeforeProcessFn.value()(rq);
        }

        // Do HTTP RQ
        httpRs = iHttpClient.V().DoRqAndWaitForRs(httpRq, GpHttpClient::ErorrMode::THROW_ON_NOT_200);
    }

    if (aAfterProcessFn.has_value())
    {
        auto rs = GpAny{GpHttpResponse::SP(httpRs)};
        aAfterProcessFn.value()(rs);
    }

    // Deserialize RS
    const GpHttpBodyPayload& rsBodyPayload = httpRs.V().iBody.V();
    THROW_COND_GP
    (
        rsBodyPayload.Type() == GpHttpBodyPayloadType::FIXED_SIZE,
        "Only GpHttpBodyPayloadType::FIXED_SIZE supported"
    );

    const GpHttpBodyPayloadFixed& rsBodyPayloadFixed = static_cast<const GpHttpBodyPayloadFixed&>(rsBodyPayload);

    return serializer.ToObject(rsBodyPayloadFixed.Data(), aRsTypeStructVariants);
}

}// namespace GPlatform
