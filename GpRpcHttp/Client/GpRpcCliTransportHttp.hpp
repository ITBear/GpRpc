#pragma once

#include "../../GpRpcCore/Client/GpRpcCliTransport.hpp"

#include <GpCore2/GpReflection/Serializers/GpReflectSerializer.hpp>
#include <GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Client/GpHttpClient.hpp>
#include <optional>

namespace GPlatform {

class GpRpcCliTransportHttp final: public GpRpcCliTransport
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttp)
    CLASS_DD(GpRpcCliTransportHttp)

public:
                                GpRpcCliTransportHttp   (GpReflectSerializer::SP    aSerializer,
                                                         GpHttpClient::SP           aHttpClient) noexcept;
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
    GpHttpClient::SP            iHttpClient;
};

}// namespace GPlatform
