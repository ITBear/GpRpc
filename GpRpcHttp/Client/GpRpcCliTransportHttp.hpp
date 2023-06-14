#pragma once

#include "../GpRpcHttp_global.hpp"
#include "../../GpRpcCore/Client/GpRpcCliTransport.hpp"
#include "../../../GpCore2/GpReflection/Serializers/GpReflectSerializer.hpp"
#include "../../../GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Client/GpHttpClient.hpp"
#include <optional>

namespace GPlatform {

class GpRpcCliTransportHttp final: public GpRpcCliTransport
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttp)
    CLASS_DD(GpRpcCliTransportHttp)

public:
    inline                      GpRpcCliTransportHttp   (GpReflectSerializer::SP    aSerializer,
                                                         GpHttpClient::SP           aHttpClient) noexcept;
    inline                      GpRpcCliTransportHttp   (std::u8string              aURL,
                                                         GpReflectSerializer::SP    aSerializer,
                                                         GpHttpClient::SP           aHttpClient) noexcept;
    virtual                     ~GpRpcCliTransportHttp  (void) noexcept override final;

    std::u8string_view          URL                     (void) const noexcept {return iURL;}
    void                        SetURL                  (std::u8string_view aURL) {iURL = aURL;}

    virtual GpReflectObject::SP ProcessRQ               (std::optional<GpReflectObject::C::Ref::CVal>   aRq,
                                                         const std::vector<const GpReflectModel*>&      aRsTypeStructVariants,
                                                         std::optional<SerializeRqFnT>                  aBeforeSerializeRqFn,
                                                         std::optional<SerializeRqFnT>                  aAfterSerializeRqFn,
                                                         std::optional<ProcessRqRsFnT>                  aBeforeProcessFn,
                                                         std::optional<ProcessRqRsFnT>                  aAfterProcessFn) override final;

private:
    std::u8string               iURL;
    GpReflectSerializer::SP     iSerializer;
    GpHttpClient::SP            iHttpClient;
};

GpRpcCliTransportHttp::GpRpcCliTransportHttp
(
    GpReflectSerializer::SP aSerializer,
    GpHttpClient::SP        aHttpClient
) noexcept:
iSerializer(std::move(aSerializer)),
iHttpClient(std::move(aHttpClient))
{
}

GpRpcCliTransportHttp::GpRpcCliTransportHttp
(
    std::u8string           aURL,
    GpReflectSerializer::SP aSerializer,
    GpHttpClient::SP        aHttpClient
) noexcept:
iURL(std::move(aURL)),
iSerializer(std::move(aSerializer)),
iHttpClient(std::move(aHttpClient))
{
}

}//namespace GPlatform
