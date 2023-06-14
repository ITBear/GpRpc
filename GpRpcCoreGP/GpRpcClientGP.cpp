#include "GpRpcClientGP.hpp"
#include "RqRs/GpRpcRqRsGP.hpp"
#include "../../GpCore2/GpReflection/GpReflectManager.hpp"
#include "../../GpCore2/GpUtils/Exceptions/GpExceptionCode.hpp"
#include "../../GpCore2/GpUtils/Exceptions/GpExceptionTextCode.hpp"

namespace GPlatform {

void    GpRpcClientGP::CheckRsResult
(
    const GpRpcRsIfDesc&    aRsDesc,
    std::u8string_view      aMethodName
)
{
    GpReflectObject::CSP resCSP = aRsDesc.Result();

    if (resCSP.IsNULL())
    {
        return;
    }

    const auto& res = GpReflectManager::S().CastRef<const GPlatform::GpRpcRsResultGPDesc>(resCSP.V());

    THROW_COND_TEXT_CODE_GP
    (
        res.code == u8"OK"_sv,
        [aMethodName, &res]()
        {
            return u8"API call return error. Method '"_sv + aMethodName + u8"', code " + res.code + u8", message: "_sv + res.msg;
        },
        res.code
    );
}

void    GpRpcClientGP::OnBeforeRQ (GpRpcRqIfDesc& /*aRq*/)
{
    //NOP
}

}//namespace GPlatform
