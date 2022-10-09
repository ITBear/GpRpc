#pragma once

#include "../GpRpcHttp_global.hpp"
#include <optional>

namespace GPlatform::RPC {

class GpRpcCliTransportHttp final: public GpRpcCliTransport
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttp)
    CLASS_DD(GpRpcCliTransportHttp)

public:
    inline                      GpRpcCliTransportHttp   (GpReflectSerializer::SP    aSerializer,
                                                         GpHttpClient::SP           aHttpClient) noexcept;
    inline                      GpRpcCliTransportHttp   (std::string                aURL,
                                                         GpReflectSerializer::SP    aSerializer,
                                                         GpHttpClient::SP           aHttpClient) noexcept;
    virtual                     ~GpRpcCliTransportHttp  (void) noexcept override final;

    std::string_view            URL                     (void) const noexcept {return iURL;}
    void                        SetURL                  (std::string_view aURL) {iURL = aURL;}

    virtual GpReflectObject::SP ProcessRQ               (const GpReflectObject&                     aRq,
                                                         const std::vector<const GpReflectModel*>&  aRsTypeStructVariants,
                                                         std::optional<SerializeRqFnT>              aBeforeSerializeRqFn,
                                                         std::optional<SerializeRqFnT>              aAfterSerializeRqFn,
                                                         std::optional<ProcessRqRsFnT>              aBeforeProcessFn,
                                                         std::optional<ProcessRqRsFnT>              aAfterProcessFn) override final;

private:
    std::string                 iURL;
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
    std::string             aURL,
    GpReflectSerializer::SP aSerializer,
    GpHttpClient::SP        aHttpClient
) noexcept:
iURL(std::move(aURL)),
iSerializer(std::move(aSerializer)),
iHttpClient(std::move(aHttpClient))
{
}

}//namespace GPlatform::RPC
