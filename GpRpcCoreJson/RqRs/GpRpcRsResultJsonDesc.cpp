#include "GpRpcRsResultJsonDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRsResultJsonDesc, GP_MODULE_UUID)

GpRpcRsResultJsonDesc::GpRpcRsResultJsonDesc (void) noexcept
{
}

GpRpcRsResultJsonDesc::GpRpcRsResultJsonDesc (const GpRpcRsResultJsonDesc& aDesc):
GpRpcRsResultIfDesc(aDesc),
code(aDesc.code),
message(aDesc.message)
{
}

GpRpcRsResultJsonDesc::GpRpcRsResultJsonDesc (GpRpcRsResultJsonDesc&& aDesc) noexcept:
GpRpcRsResultIfDesc(std::move(aDesc)),
code(std::move(aDesc.code)),
message(std::move(aDesc.message))
{
}

GpRpcRsResultJsonDesc::~GpRpcRsResultJsonDesc (void) noexcept
{
}

void    GpRpcRsResultJsonDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(code);
    PROP(message);
}

}//namespace GPlatform::RPC
