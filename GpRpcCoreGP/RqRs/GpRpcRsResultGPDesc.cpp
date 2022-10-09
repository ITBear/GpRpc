#include "GpRpcRsResultGPDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRsResultGPDesc, GP_MODULE_UUID)

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc (const GpRpcRsResultGPDesc& aDesc):
GpRpcRsResultIfDesc(aDesc),
code(aDesc.code),
msg(aDesc.msg)
{
}

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc (GpRpcRsResultGPDesc&& aDesc) noexcept:
GpRpcRsResultIfDesc(std::move(aDesc)),
code(std::move(aDesc.code)),
msg(std::move(aDesc.msg))
{
}

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc
(
    std::string aCode,
    std::string aMsg
) noexcept:
code(std::move(aCode)),
msg(std::move(aMsg))
{
}

GpRpcRsResultGPDesc::~GpRpcRsResultGPDesc (void) noexcept
{
}

void    GpRpcRsResultGPDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(code);
    PROP(msg);
}

}//namespace GPlatform::RPC
