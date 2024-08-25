#pragma once

#include <GpRpc/GpRpcHttp/GpRpcHttp_global.hpp>
#include <GpRpc/GpRpcCore/Server/GpRpcMethodsManagersGroup.hpp>
#include <GpRpc/GpRpcCore/Server/GpRpcMethodDetectorFactory.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/RequestHandlers/GpHttpRequestHandler.hpp>
#include <GpCore2/GpReflection/Serializers/GpReflectSerializerFactory.hpp>

namespace GPlatform {

class GP_RPC_HTTP_API GpRpcSrvRequestHandlerHttp final: public GpHttpRequestHandler
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcSrvRequestHandlerHttp)
    CLASS_DD(GpRpcSrvRequestHandlerHttp)

public:
    inline                          GpRpcSrvRequestHandlerHttp  (GpRpcMethodsManagersGroup::SP  aRpcManagersGroup,
                                                                 GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                 GpRpcMethodDetectorFactory::SP aMethodDetectorFactory) noexcept;
    virtual                         ~GpRpcSrvRequestHandlerHttp (void) noexcept override final;

protected:
    virtual GpHttpResponse::SP      OnRequest                   (GpHttpRequest& aRequest) override final;

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
iRpcManagersGroup        (std::move(aRpcManagersGroup)),
iReflectSerializerFactory(std::move(aReflectSerializerFactory)),
iMethodDetectorFactory   (std::move(aMethodDetectorFactory))
{
}

}// namespace GPlatform
