#pragma once

#include "../GpRpcHttp_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_HTTP_API GpRpcSrvRequestHandlerHttpFactory final: public GpHttpRequestHandlerFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcSrvRequestHandlerHttpFactory)
    CLASS_DD(GpRpcSrvRequestHandlerHttpFactory)

public:
    inline                              GpRpcSrvRequestHandlerHttpFactory   (GpRpcMethodsManagersGroup::SP  aRpcManagersGroup,
                                                                             GpReflectSerializerFactory::SP aSerializerFactory,
                                                                             GpRpcMethodDetectorFactory::SP aMethodDetectorFactory) noexcept;
    virtual                             ~GpRpcSrvRequestHandlerHttpFactory  (void) noexcept override final;

    virtual GpSP<GpHttpRequestHandler>  NewInstance                         (void) const override final;

private:
    GpRpcMethodsManagersGroup::SP       iRpcManagersGroup;
    GpReflectSerializerFactory::SP      iSerializerFactory;
    GpRpcMethodDetectorFactory::SP      iMethodDetectorFactory;
};

GpRpcSrvRequestHandlerHttpFactory::GpRpcSrvRequestHandlerHttpFactory
(
    GpRpcMethodsManagersGroup::SP   aRpcManagersGroup,
    GpReflectSerializerFactory::SP  aSerializerFactory,
    GpRpcMethodDetectorFactory::SP  aMethodDetectorFactory
) noexcept:
iRpcManagersGroup(std::move(aRpcManagersGroup)),
iSerializerFactory(std::move(aSerializerFactory)),
iMethodDetectorFactory(std::move(aMethodDetectorFactory))
{
}

}//namespace GPlatform::RPC
