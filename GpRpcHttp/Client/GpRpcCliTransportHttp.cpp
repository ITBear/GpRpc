#include "GpRpcCliTransportHttp.hpp"

namespace GPlatform::RPC {

GpRpcCliTransportHttp::~GpRpcCliTransportHttp (void) noexcept
{
}

GpReflectObject::SP GpRpcCliTransportHttp::ProcessRQ
(
    const GpReflectObject&                      aRq,
    const std::vector<const GpReflectModel*>&   aRsTypeStructVariants,
    std::optional<SerializeRqFnT>               aBeforeSerializeRqFn,
    std::optional<SerializeRqFnT>               aAfterSerializeRqFn,
    std::optional<ProcessRqRsFnT>               aBeforeProcessFn,
    std::optional<ProcessRqRsFnT>               aAfterProcessFn
)
{
    const GpReflectSerializer& serializer = iSerializer.V();

    //RQ/RS
    GpHttpRequest::SP   httpRq;
    GpHttpResponse::SP  httpRs;

    {
        //Serialize RQ to body
        GpBytesArray body;
        {
            body.resize(1024);//TODO: move to factory

            GpByteWriterStorageByteArray    bodyStorage(body);
            GpByteWriter                    bodyWriter(bodyStorage);
            SerializeRqFnRes                serializeRqFnRes = SerializeRqFnRes::CONTINUE;

            if (aBeforeSerializeRqFn.has_value())
            {
                serializeRqFnRes = aBeforeSerializeRqFn.value()(bodyWriter);
            }

            if (serializeRqFnRes == SerializeRqFnRes::CONTINUE)
            {
                serializer.FromObject(aRq, bodyWriter);
            }

            if (aAfterSerializeRqFn.has_value())
            {
                aAfterSerializeRqFn.value()(bodyWriter);
            }

            bodyWriter.ShrinkToFit();
        }

        //Prepate HTTP RQ
        GpHttpHeaders rqHeaders;

        httpRq = MakeSP<GpHttpRequest>
        (
            GpHttpVersion::HTTP_1_1,
            GpHttpRequestType::POST,
            iURL,
            rqHeaders,
            std::move(body)
        );

        if (aBeforeProcessFn.has_value())
        {
            aBeforeProcessFn.value()(std::make_any<GpHttpRequest::SP>(httpRq));
        }

        //Do HTTP RQ
        httpRs = iHttpClient.V().Do(httpRq, GpHttpClient::ErorrMode::THROW_ON_NOT_200);
    }

    if (aAfterProcessFn.has_value())
    {
        aAfterProcessFn.value()(std::make_any<GpHttpResponse::SP>(httpRs));
    }

    //Deserialize RS
    return serializer.ToObject(httpRs.V().body, aRsTypeStructVariants);
}

}//namespace GPlatform::RPC
