#include "GpRpcClientGP.hpp"
#include "RqRs/GpRpcRqRsGP.hpp"

namespace GPlatform::RPC {

void    GpRpcClientGP::CheckRsResult
(
    const GpRpcRsIfDesc&    aRsDesc,
    std::string_view        aMethodName
)
{
    GPlatform::RPC::GpRpcRsResultIfDesc::CSP resCSP = aRsDesc.Result();

    if (resCSP.IsNULL())
    {
        return;
    }

    const auto& res = GpReflectManager::S().CastRef<const GPlatform::RPC::GpRpcRsResultGPDesc>(resCSP.V());

    THROW_COND_GP
    (
        res.code == std::string("OK"),
        "API call return error. Method '"_sv + aMethodName + "', code " + res.code + ", message: "_sv + res.msg
    );
}

void    GpRpcClientGP::OnBeforeRQ (GpRpcRqIfDesc& /*aRq*/)
{
    //NOP
}

}//namespace GPlatform::RPC
