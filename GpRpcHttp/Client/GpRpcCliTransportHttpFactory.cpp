#include "GpRpcCliTransportHttpFactory.hpp"
#include "GpRpcCliTransportHttp.hpp"

namespace GPlatform::RPC {

GpRpcCliTransportHttpFactory::~GpRpcCliTransportHttpFactory (void) noexcept
{
}

GpRpcCliTransport::SP   GpRpcCliTransportHttpFactory::NewInstance (void) const
{
    return MakeSP<GpRpcCliTransportHttp>
    (
        iURL,
        iReflectSerializerFactory.V().NewInstance(),
        iHttpClientFactory.V().NewInstance()
    );
}

}//namespace GPlatform::RPC
