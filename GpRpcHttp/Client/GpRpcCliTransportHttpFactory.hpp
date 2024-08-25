#pragma once

#include <GpRpc/GpRpcHttp/GpRpcHttp_global.hpp>
#include <GpRpc/GpRpcCore/Client/GpRpcCliTransportFactory.hpp>
#include <GpCore2/GpReflection/Serializers/GpReflectSerializerFactory.hpp>
#include <GpNetwork/GpNetworkCore/Sockets/GpSocketFlags.hpp>
#include <GpNetwork/GpNetworkCore/Pollers/GpIOEventPollerCatalog.hpp>

namespace GPlatform {

class GP_RPC_HTTP_API GpRpcCliTransportHttpFactory final: public GpRpcCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttpFactory)
    CLASS_DD(GpRpcCliTransportHttpFactory)

public:
                                    GpRpcCliTransportHttpFactory    (GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpSocketFlags                  aSocketFlags,
                                                                     GpIOEventPollerIdx             aIOEventPollerIdx,
                                                                     milliseconds_t                 aConnectTimeout,
                                                                     milliseconds_t                 aRequestTimeout) noexcept;
    virtual                         ~GpRpcCliTransportHttpFactory   (void) noexcept override final;

    virtual GpRpcCliTransport::SP   NewInstance                     (void) const override final;

private:
    GpReflectSerializerFactory::SP  iReflectSerializerFactory;
    const GpSocketFlags             iSocketFlags;
    const GpIOEventPollerIdx        iIOEventPollerIdx;
    const milliseconds_t            iConnectTimeout;
    const milliseconds_t            iRequestTimeout;
};

}// namespace GPlatform
