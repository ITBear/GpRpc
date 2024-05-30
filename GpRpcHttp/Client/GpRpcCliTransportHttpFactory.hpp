#pragma once

#include "../GpRpcHttp_global.hpp"
#include "../../GpRpcCore/Client/GpRpcCliTransportFactory.hpp"

#include <GpCore2/GpReflection/Serializers/GpReflectSerializerFactory.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Client/GpHttpClientFactory.hpp>

namespace GPlatform {

class GP_RPC_HTTP_API GpRpcCliTransportHttpFactory final: public GpRpcCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttpFactory)
    CLASS_DD(GpRpcCliTransportHttpFactory)

public:
                                    GpRpcCliTransportHttpFactory    (GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory,
                                                                     GpSocketFlags                  aSocketFlags,
                                                                     GpIOEventPollerIdx             aIOEventPollerIdx,
                                                                     milliseconds_t                 aConnectTimeout) noexcept;
                                    GpRpcCliTransportHttpFactory    (GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory,
                                                                     GpSocketFlags                  aSocketFlags,
                                                                     GpIOEventPollerIdx             aIOEventPollerIdx,
                                                                     milliseconds_t                 aConnectTimeout,
                                                                     std::string                    aTaskName) noexcept;
    virtual                         ~GpRpcCliTransportHttpFactory   (void) noexcept override final;

    virtual GpRpcCliTransport::SP   NewInstance                     (void) const override final;

private:
    GpReflectSerializerFactory::SP  iReflectSerializerFactory;
    GpHttpClientFactory::SP         iHttpClientFactory;
    const GpSocketFlags             iSocketFlags;
    const GpIOEventPollerIdx        iIOEventPollerIdx;
    const milliseconds_t            iConnectTimeout;
    const std::string               iTaskName;
};

}// namespace GPlatform
