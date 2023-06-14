#pragma once

#include "../GpRpcHttp_global.hpp"
#include "../../GpRpcCore/Client/GpRpcCliTransportFactory.hpp"
#include "../../../GpCore2/GpReflection/Serializers/GpReflectSerializerFactory.hpp"
#include "../../../GpNetwork/GpNetworkHttp/GpNetworkHttpCore/Client/GpHttpClientFactory.hpp"

namespace GPlatform {

class GP_RPC_HTTP_API GpRpcCliTransportHttpFactory final: public GpRpcCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttpFactory)
    CLASS_DD(GpRpcCliTransportHttpFactory)

public:
    inline                          GpRpcCliTransportHttpFactory    (GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory) noexcept;
    inline                          GpRpcCliTransportHttpFactory    (std::u8string_view             aURL,
                                                                     GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory);
    virtual                         ~GpRpcCliTransportHttpFactory   (void) noexcept override final;

    virtual GpRpcCliTransport::SP   NewInstance                     (void) const override final;

private:
    const std::u8string             iURL;
    GpReflectSerializerFactory::SP  iReflectSerializerFactory;
    GpHttpClientFactory::SP         iHttpClientFactory;
};

GpRpcCliTransportHttpFactory::GpRpcCliTransportHttpFactory
(
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpHttpClientFactory::SP         aHttpClientFactory
) noexcept:
iReflectSerializerFactory(std::move(aReflectSerializerFactory)),
iHttpClientFactory(std::move(aHttpClientFactory))
{
}

GpRpcCliTransportHttpFactory::GpRpcCliTransportHttpFactory
(
    std::u8string_view              aURL,
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpHttpClientFactory::SP         aHttpClientFactory
):
iURL(aURL),
iReflectSerializerFactory(std::move(aReflectSerializerFactory)),
iHttpClientFactory(std::move(aHttpClientFactory))
{
}

}//namespace GPlatform
