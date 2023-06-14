#include "GpRpcSrvRequestHandlerHttpFactory.hpp"
#include "GpRpcSrvRequestHandlerHttp.hpp"

namespace GPlatform {

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

}//namespace GPlatform
