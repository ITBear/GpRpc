#include "GpRpcClientSidGP.hpp"
#include "RqRs/GpRpcRqGPDesc.hpp"

namespace GPlatform {

GpRpcClientSidGP::~GpRpcClientSidGP (void) noexcept
{
}

void    GpRpcClientSidGP::OnBeforeRQ (GPlatform::GpRpcRqIfDesc& aRq)
{
    GpRpcClientGP::OnBeforeRQ(aRq);

    GPlatform::GpRpcRqGPDesc& rq = static_cast<GPlatform::GpRpcRqGPDesc&>(aRq);
    rq.sid  = iSid;
}

}// namespace GPlatform
