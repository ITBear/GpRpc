#include <GpRpc/GpRpcHttp/Server/GpRpcSrvRequestHandlerHttpFactory.hpp>
#include <GpRpc/GpRpcHttp/Server/GpRpcSrvRequestHandlerHttp.hpp>

namespace GPlatform {

GpRpcSrvRequestHandlerHttpFactory::GpRpcSrvRequestHandlerHttpFactory
(
    GpRpcMethodsManagersGroup::SP   aRpcManagersGroup,
    GpReflectSerializerFactory::SP  aSerializerFactory,
    GpRpcMethodDetectorFactory::SP  aMethodDetectorFactory
) noexcept:
iRpcManagersGroup     {std::move(aRpcManagersGroup)},
iSerializerFactory    {std::move(aSerializerFactory)},
iMethodDetectorFactory{std::move(aMethodDetectorFactory)}
{
}

GpRpcSrvRequestHandlerHttpFactory::~GpRpcSrvRequestHandlerHttpFactory (void) noexcept
{
}

GpHttpRequestHandler::SP    GpRpcSrvRequestHandlerHttpFactory::NewInstance (void) const
{
    return MakeSP<GpRpcSrvRequestHandlerHttp>
    (
        iRpcManagersGroup,
        iSerializerFactory,
        iMethodDetectorFactory
    );
}

}// namespace GPlatform
