#include "GpRpcCliTransportHttpFactory.hpp"
#include "GpRpcCliTransportHttp.hpp"

namespace GPlatform {

GpRpcCliTransportHttpFactory::GpRpcCliTransportHttpFactory
(
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpHttpClientFactory::SP         aHttpClientFactory,
    const GpSocketFlags             aSocketFlags,
    const GpIOEventPollerIdx        aIOEventPollerIdx,
    const milliseconds_t            aConnectTimeout
) noexcept:
iReflectSerializerFactory{std::move(aReflectSerializerFactory)},
iHttpClientFactory       {std::move(aHttpClientFactory)},
iSocketFlags             {aSocketFlags},
iIOEventPollerIdx        {aIOEventPollerIdx},
iConnectTimeout          {aConnectTimeout}
{
}

GpRpcCliTransportHttpFactory::GpRpcCliTransportHttpFactory
(
    GpReflectSerializerFactory::SP  aReflectSerializerFactory,
    GpHttpClientFactory::SP         aHttpClientFactory,
    const GpSocketFlags             aSocketFlags,
    const GpIOEventPollerIdx        aIOEventPollerIdx,
    const milliseconds_t            aConnectTimeout,
    std::string                     aTaskName
) noexcept:
iReflectSerializerFactory{std::move(aReflectSerializerFactory)},
iHttpClientFactory       {std::move(aHttpClientFactory)},
iSocketFlags             {aSocketFlags},
iIOEventPollerIdx        {aIOEventPollerIdx},
iConnectTimeout          {aConnectTimeout},
iTaskName                {std::move(aTaskName)}
{
}

GpRpcCliTransportHttpFactory::~GpRpcCliTransportHttpFactory (void) noexcept
{
}

GpRpcCliTransport::SP   GpRpcCliTransportHttpFactory::NewInstance (void) const
{
    return MakeSP<GpRpcCliTransportHttp>
    (
        iReflectSerializerFactory.V().NewInstance(),
        iHttpClientFactory.V().NewInstance
        (
            iSocketFlags,
            iIOEventPollerIdx,
            iConnectTimeout,
            iTaskName
        )
    );
}

}// namespace GPlatform
