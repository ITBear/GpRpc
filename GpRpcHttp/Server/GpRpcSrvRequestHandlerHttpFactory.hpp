#pragma once

#include "../GpRpcHttp_global.hpp"
#include "../../GpRpcCore/Server/GpRpcMethodsManagersGroup.hpp"
#include "../../GpRpcCore/Server/GpRpcMethodDetectorFactory.hpp"

#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/RequestHandlers/GpHttpRequestHandlerFactory.hpp>
#include <GpCore2/GpReflection/Serializers/GpReflectSerializerFactory.hpp>

namespace GPlatform {

class GP_RPC_HTTP_API GpRpcSrvRequestHandlerHttpFactory final: public GpHttpRequestHandlerFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcSrvRequestHandlerHttpFactory)
    CLASS_DD(GpRpcSrvRequestHandlerHttpFactory)

public:
                                        GpRpcSrvRequestHandlerHttpFactory   (GpRpcMethodsManagersGroup::SP  aRpcManagersGroup,
                                                                             GpReflectSerializerFactory::SP aSerializerFactory,
                                                                             GpRpcMethodDetectorFactory::SP aMethodDetectorFactory) noexcept;
    virtual                             ~GpRpcSrvRequestHandlerHttpFactory  (void) noexcept override final;

    virtual GpSP<GpHttpRequestHandler>  NewInstance                         (void) const override final;

private:
    GpRpcMethodsManagersGroup::SP       iRpcManagersGroup;
    GpReflectSerializerFactory::SP      iSerializerFactory;
    GpRpcMethodDetectorFactory::SP      iMethodDetectorFactory;
};

}// namespace GPlatform
