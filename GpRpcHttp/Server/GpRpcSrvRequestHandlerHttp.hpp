#pragma once

#include "../GpRpcHttp_global.hpp"

namespace GPlatform::RPC {

class GpRpcSrvRequestHandlerHttp: public GpHttpRequestHandler
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcSrvRequestHandlerHttp)
    CLASS_DD(GpRpcSrvRequestHandlerHttp)

public:
    inline                          GpRpcSrvRequestHandlerHttp  (GpRpcMethodsManagersGroup::SP  aRpcManagersGroup,
                                                                 GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                 GpRpcMethodDetectorFactory::SP aMethodDetectorFactory) noexcept;
    virtual                         ~GpRpcSrvRequestHandlerHttp (void) noexcept override;

    virtual GpHttpResponse::SP      OnRequest                   (const GpHttpRequest& aRequest) override final;

private:
    GpRpcMethodsManagersGroup::SP   iRpcManagersGroup;
    GpReflectSerializerFactory::SP  iReflectSerializerFactory;
    GpRpcMethodDetectorFactory::SP  iMethodDetectorFactory;
};

GpRpcSrvRequestHandlerHttp::GpRpcSrvRequestHandlerHttp
(
    GpRpcMethodsManagersGroup::SP   aRpcManagersGroup,
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpRpcMethodDetectorFactory::SP  aMethodDetectorFactory
) noexcept:
iRpcManagersGroup(std::move(aRpcManagersGroup)),
iReflectSerializerFactory(std::move(aReflectSerializerFactory)),
iMethodDetectorFactory(std::move(aMethodDetectorFactory))
{
}

}//namespace GPlatform::RPC
