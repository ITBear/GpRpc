#include "GpRpcClientGP.hpp"

#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpUtils/Exceptions/GpExceptionCode.hpp>
#include <GpCore2/GpUtils/Exceptions/GpExceptionTextCode.hpp>

#include "RqRs/GpRpcRsResultGPDesc.hpp"

namespace GPlatform {

void    GpRpcClientGP::CheckRsResult
(
    const GpRpcRsIfDesc&    aRsDesc,
    std::string_view        aMethodName
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
        res.code == "OK",
        [aMethodName, &res]()
        {
            return fmt::format
            (
                "API call return error. Method '{}', code {}, message: {}",
                aMethodName,
                res.code,
                res.msg
            );
        },
        res.code
    );
}

void    GpRpcClientGP::OnBeforeRQ (GpRpcRqIfDesc& /*aRq*/)
{
    // NOP
}

}// namespace GPlatform
