#include <GpRpc/GpRpcHttp/Client/GpRpcCliTransportHttpFactory.hpp>
#include <GpRpc/GpRpcHttp/Client/GpRpcCliTransportHttp.hpp>

namespace GPlatform {

GpRpcCliTransportHttpFactory::GpRpcCliTransportHttpFactory
(
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    const GpSocketFlags             aSocketFlags,
    const GpIOEventPollerIdx        aIOEventPollerIdx,
    const milliseconds_t            aConnectTimeout,
    const milliseconds_t            aRequestTimeout
) noexcept:
iReflectSerializerFactory{std::move(aReflectSerializerFactory)},
iSocketFlags             {aSocketFlags},
iIOEventPollerIdx        {aIOEventPollerIdx},
iConnectTimeout          {aConnectTimeout},
iRequestTimeout          {aRequestTimeout}
{
}

GpRpcCliTransportHttpFactory::~GpRpcCliTransportHttpFactory (void) noexcept
{
}

GpRpcCliTransport::SP   GpRpcCliTransportHttpFactory::NewInstance (void) const
{
    return MakeSP<GpRpcCliTransportHttp>
    (
        iReflectSerializerFactory.Vn().NewInstance(),
        iSocketFlags,
        iIOEventPollerIdx,
        iConnectTimeout,
        iRequestTimeout
    );
}

}// namespace GPlatform
