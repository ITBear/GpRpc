#include "GpRpcClientSidGP.hpp"
#include "RqRs/GpRpcRqRsGP.hpp"

namespace GPlatform::RPC {

GpRpcClientSidGP::~GpRpcClientSidGP (void) noexcept
{
}

void    GpRpcClientSidGP::OnBeforeRQ (GPlatform::RPC::GpRpcRqIfDesc& aRq)
{
    GpRpcClientGP::OnBeforeRQ(aRq);

    GPlatform::RPC::GpRpcRqGPDesc& rq = static_cast<GPlatform::RPC::GpRpcRqGPDesc&>(aRq);
    rq.sid  = iSid;
}

}//namespace GPlatform::RPC
