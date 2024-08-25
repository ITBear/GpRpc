#pragma once

#include <GpRpc/GpRpcCore/Client/GpRpcCliTransport.hpp>
#include <GpCore2/GpReflection/Serializers/GpReflectSerializer.hpp>
#include <GpNetwork/GpNetworkCore/Sockets/GpSocketFlags.hpp>
#include <GpNetwork/GpNetworkCore/Pollers/GpIOEventPollerCatalog.hpp>

namespace GPlatform {

class GpRpcCliTransportHttp final: public GpRpcCliTransport
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttp)
    CLASS_DD(GpRpcCliTransportHttp)

public:
                                GpRpcCliTransportHttp   (GpReflectSerializer::SP    aSerializer,
                                                         GpSocketFlags              aSocketFlags,
                                                         GpIOEventPollerIdx         aIOEventPollerIdx,
                                                         milliseconds_t             aConnectTimeout,
                                                         milliseconds_t             aRequestTimeout) noexcept;
    virtual                     ~GpRpcCliTransportHttp  (void) noexcept override final;

    virtual GpReflectObject::SP ProcessRQ               (const GpUrl&                                   aUrl,
                                                         std::optional<GpReflectObject::C::Ref::CVal>   aRq,
                                                         const std::vector<const GpReflectModel*>&      aRsTypeStructVariants,
                                                         std::optional<SerializeRqFnT>                  aBeforeSerializeRqFn,
                                                         std::optional<SerializeRqFnT>                  aAfterSerializeRqFn,
                                                         std::optional<ProcessRqRsFnT>                  aBeforeProcessFn,
                                                         std::optional<ProcessRqRsFnT>                  aAfterProcessFn) override final;

private:
    GpReflectSerializer::SP     iSerializer;
    const GpSocketFlags         iSocketFlags;
    const GpIOEventPollerIdx    iIOEventPollerIdx;
    const milliseconds_t        iConnectTimeout;
    const milliseconds_t        iRequestTimeout;
};

}// namespace GPlatform
