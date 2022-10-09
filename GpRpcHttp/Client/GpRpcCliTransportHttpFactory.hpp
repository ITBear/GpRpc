#pragma once

#include "../GpRpcHttp_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_HTTP_API GpRpcCliTransportHttpFactory final: public GpRpcCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcCliTransportHttpFactory)
    CLASS_DD(GpRpcCliTransportHttpFactory)

public:
    inline                          GpRpcCliTransportHttpFactory    (GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory) noexcept;
    inline                          GpRpcCliTransportHttpFactory    (std::string_view               aURL,
                                                                     GpReflectSerializerFactory::SP aReflectSerializerFactory,
                                                                     GpHttpClientFactory::SP        aHttpClientFactory);
    virtual                         ~GpRpcCliTransportHttpFactory   (void) noexcept override final;

    virtual GpRpcCliTransport::SP   NewInstance                     (void) const override final;

private:
    const std::string               iURL;
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
    std::string_view                aURL,
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpHttpClientFactory::SP         aHttpClientFactory
):
iURL(aURL),
iReflectSerializerFactory(std::move(aReflectSerializerFactory)),
iHttpClientFactory(std::move(aHttpClientFactory))
{
}

}//namespace GPlatform::RPC
