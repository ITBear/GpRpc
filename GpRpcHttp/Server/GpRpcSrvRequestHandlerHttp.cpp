#include "GpRpcSrvRequestHandlerHttp.hpp"

#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Body/GpHttpBodyPayloadFixed.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/RqRs/GpHttpResponseNoBodyDesc.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Body/GpHttpBodyPayloadFixed.hpp>

namespace GPlatform {

GpRpcSrvRequestHandlerHttp::~GpRpcSrvRequestHandlerHttp (void) noexcept
{
}

GpHttpResponse::SP  GpRpcSrvRequestHandlerHttp::OnRequest (GpHttpRequest& aRequest)
{
    GpRpcRqIfDesc::SP rq;
    GpRpcRsIfDesc::SP rs;

    auto serializer = iReflectSerializerFactory.V().NewInstance();

    GpRpcMethodsManager::SP apiMethodsManager;

    try
    {
        GpHttpBodyPayload& rqBodyPayload = aRequest.iBody.V();

        THROW_COND_HTTP
        (
            rqBodyPayload.Type() == GpHttpBodyPayloadType::FIXED_SIZE,
            GpHttpResponseCode::BAD_REQUEST_400,
            "Only GpHttpBodyPayloadType::FIXED_SIZE supported"
        );

        GpHttpBodyPayloadFixed& rqBodyPayloadFixed  = static_cast<GpHttpBodyPayloadFixed&>(rqBodyPayload);
        GpSpanByteRW            rqBodyPayloadData   = rqBodyPayloadFixed.Data();

        THROW_COND_HTTP
        (
            !rqBodyPayloadData.Empty(),
            GpHttpResponseCode::BAD_REQUEST_400,
            "Empty body"
        );

        GpBytesArray nullTerminatedData;
        if (rqBodyPayloadData[rqBodyPayloadData.Count() - 1] != std::byte{0})
        {
            // String must be null terminated
            nullTerminatedData.resize(rqBodyPayloadData.Count() + 1);
            std::memcpy(std::data(nullTerminatedData), rqBodyPayloadData.Ptr(), rqBodyPayloadData.Count());
            nullTerminatedData[std::size(nullTerminatedData) - 1] = std::byte{0};

            rqBodyPayloadData = nullTerminatedData;
        }

        // Detect type
        auto methodDetector             = iMethodDetectorFactory.V().NewInstance(rqBodyPayloadData);
        auto [methodName, rqBodyCtx]    = methodDetector.V().DetectApiMethodName();
        auto [managerSP, methodSP]      = iRpcManagersGroup.V().Find(methodName);

        if (   managerSP.IsNotNULL()
            && methodSP.IsNotNULL())
        {
            GpRpcMethod& method = methodSP.V();
            apiMethodsManager   = managerSP;

            // Deserialize RQ data
            rq = serializer.Vn().ToObject(rqBodyCtx.V(), method.RqReflectModel().Vn()).CastAs<GpRpcRqIfDesc::SP>();

            // Call method
            GpReflectObject::SP result = apiMethodsManager.V().CallAndCatch
            (
                [&]()
                {
                    rs = method.Process(rq.Vn());
                }
            );

            if (rs.IsNULL())
            {
                rs = method.RsReflectModel().Vn().NewInstance().CastAs<GpRpcRsIfDesc::SP>();
            }

            rs.V().SetResult(result);
        } else
        {
            apiMethodsManager   = iRpcManagersGroup.V().MethodNotFoundManager();
            rs                  = apiMethodsManager.V().NewDefaultRs();
            auto result         = apiMethodsManager.V().CallAndCatch
            (
                [&]()
                {
                    iRpcManagersGroup.V().ThrowMethodNotFound(methodName);
                }
            );

            rs.V().SetResult(result);
        }
    } catch (const GpHttpException&)
    {
        throw;
    } catch (const std::exception& e)
    {
        if (rs.IsNULL())
        {
            rs = apiMethodsManager.V().NewDefaultRs();
        }

        rs.V().SetResult(apiMethodsManager.V().GenResultEx(e));
    } catch (...)
    {
        if (rs.IsNULL())
        {
            rs = apiMethodsManager.V().NewDefaultRs();
        }

        rs.V().SetResult(apiMethodsManager.V().GenResultExUnknown());
    }

    // Serialize RS data
    GpBytesArray rsBody = serializer.Vn().FromObject(rs.V());

    // TODO: move to config
    GpHttpHeaders headers;
    headers
        .SetContentType(GpHttpContentType::APPLICATION_JSON, GpHttpCharset::UTF_8)
        .SetConnection(GpHttpConnectionFlag::KEEP_ALIVE)
        .SetCacheControl(GpHttpCacheControl::NO_STORE)
        .SetContentLength(std::size(rsBody));

    GpHttpResponse::SP httpRs = MakeSP<GpHttpResponse>
    (
        GpHttpResponseNoBodyDesc
        {
            GpHttpResponseCode::OK_200,
            std::move(headers)
        },
        MakeSP<GpHttpBodyPayloadFixed>(std::move(rsBody))
    );

    return httpRs;
}

}// namespace GPlatform
