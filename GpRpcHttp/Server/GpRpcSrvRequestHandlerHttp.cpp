#include "GpRpcSrvRequestHandlerHttp.hpp"

namespace GPlatform::RPC {

GpRpcSrvRequestHandlerHttp::~GpRpcSrvRequestHandlerHttp (void) noexcept
{
}

GpHttpResponse::SP  GpRpcSrvRequestHandlerHttp::OnRequest (const GpHttpRequest& aRequest)
{
    GpRpcRqIfDesc::SP rq;
    GpRpcRsIfDesc::SP rs;

    auto serializer = iReflectSerializerFactory.V().NewInstance();

    GpRpcMethodsManager::SP apiMethodsManager;

    try
    {
        const GpSpanPtrByteR rqBody = aRequest.body;

        if (rqBody.Count() == 0)
        {
            THROW_HTTP(GpHttpResponseCode::BAD_REQUEST_400, "Body is empty"_sv);
        }

        //Detect type
        auto                methodDetector          = iMethodDetectorFactory.V().NewInstance(rqBody);
        const std::string   methodName              = methodDetector.V().DetectApiMethodName();
        auto                [managerSP, methodSP]   = iRpcManagersGroup.V().FindManagerAndMethod(methodName);

        if (   managerSP.IsNotNULL()
            && methodSP.IsNotNULL())
        {
            GpRpcMethod& method = methodSP.V();
            apiMethodsManager   = managerSP;

            //Deserialize RQ data
            rq = serializer.Vn().ToObject(rqBody, method.RqReflectModel()).CastAs<GpRpcRqIfDesc::SP>();

            //Call method
            auto result = apiMethodsManager.V().CallAndCatch([&](){rs = method.Process(rq.Vn());});

            if (rs.IsNULL())
            {
                rs = method.RsReflectModel().NewInstance().CastAs<GpRpcRsIfDesc::SP>();
            }

            rs.V().SetResult(result);
        } else
        {
            apiMethodsManager = iRpcManagersGroup.V().MethodNotFoundManager();

            rs = apiMethodsManager.V().NewDefaultRs();
            auto result = apiMethodsManager.V().CallAndCatch([&](){iRpcManagersGroup.V().ThrowMethodNotFound(methodName);});
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

    //Serialize RS data
    GpBytesArray rsBody = serializer.Vn().FromObject(rs.V());

    //TODO: move to config
    GpHttpHeaders headers;
    headers
        .SetContentType(GpHttpContentType::APPLICATION_JSON, GpHttpCharset::UTF_8)
        .SetConnection(GpHttpConnectionFlag::KEEP_ALIVE)
        .SetCacheControl(GpHttpCacheControl::NO_STORE);

    GpHttpResponse::SP httpRs = MakeSP<GpHttpResponse>
    (
        GpHttpResponseCode::OK_200,
        std::move(headers),
        std::move(rsBody)
    );

    return httpRs;
}

}//namespace GPlatform::RPC
