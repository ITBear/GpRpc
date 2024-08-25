#include <GpRpc/GpRpcHttp/Client/GpRpcCliTransportHttp.hpp>
#include <GpCore2/GpUtils/Streams/GpByteWriterStorageByteArray.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Body/GpHttpBodyPayloadFixed.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Client/GpHttpClient.hpp>

namespace GPlatform {

GpRpcCliTransportHttp::GpRpcCliTransportHttp
(
    GpReflectSerializer::SP     aSerializer,
    const GpSocketFlags         aSocketFlags,
    const GpIOEventPollerIdx    aIOEventPollerIdx,
    const milliseconds_t        aConnectTimeout,
    const milliseconds_t        aRequestTimeout
) noexcept:
iSerializer      {std::move(aSerializer)},
iSocketFlags     {aSocketFlags},
iIOEventPollerIdx{aIOEventPollerIdx},
iConnectTimeout  {aConnectTimeout},
iRequestTimeout  {aRequestTimeout}
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
    GpHttpResponse::SP httpRsSP;

    {
        // Serialize RQ to body
        GpBytesArray body;
        if (aRq.has_value()) [[likely]]
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
        GpHttpClient        httpClient{iSocketFlags, iIOEventPollerIdx};// TODO: reimplement with connection pool
        GpHttpHeaders       rqHeaders;

        GpHttpRequest::SP   httpRqSP = MakeSP<GpHttpRequest>
        (
            GpHttpRequestNoBodyDesc
            {
                GpHttpVersion::HTTP_1_1,
                GpHttpRequestType::HTTP_POST,
                aUrl,
                rqHeaders
            },
            MakeSP<GpHttpBodyPayloadFixed>(std::move(body))
        );

        if (aBeforeProcessFn.has_value())
        {
            auto rq = GpAny{httpRqSP};
            aBeforeProcessFn.value()(rq);
        }

        // Do HTTP RQ
        httpRsSP = httpClient.DoAndWait
        (
            httpRqSP,
            iConnectTimeout,
            iRequestTimeout
        );

        const GpHttpResponse& httpRs = httpRsSP.V();

        // Check http RS result
        THROW_COND_HTTP
        (
            httpRs.iResponseNoBody.code == GpHttpResponseCode::OK_200,
            httpRs.iResponseNoBody.code,
            httpRs.iBody.IsNotNULL() ? static_cast<const GpHttpBodyPayloadFixed&>(httpRs.iBody.Vn()).Data().AsStringView() : ""_sv
        );

        // Check http RS body
        THROW_COND_GP
        (
            httpRs.iBody.IsNotNULL(),
            "HTTP RS body is empty"
        );
    }

    if (aAfterProcessFn.has_value())
    {
        auto rs = GpAny{httpRsSP};
        aAfterProcessFn.value()(rs);
    }

    // Deserialize RS
    const GpHttpBodyPayload& rsBodyPayload = httpRsSP.V().iBody.Vn();

    THROW_COND_GP
    (
        rsBodyPayload.Type() == GpHttpBodyPayloadType::FIXED_SIZE,
        "Only GpHttpBodyPayloadType::FIXED_SIZE supported"
    );

    const GpHttpBodyPayloadFixed& rsBodyPayloadFixed = static_cast<const GpHttpBodyPayloadFixed&>(rsBodyPayload);

    return serializer.ToObject(rsBodyPayloadFixed.Data(), aRsTypeStructVariants);
}

}// namespace GPlatform
