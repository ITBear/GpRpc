#include <GpRpc/GpRpcCoreGP/RqRs/GpRpcRsResultGPDesc.hpp>
#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpReflection/GpReflectPropUtils.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsResultGPDesc, GP_MODULE_UUID)

GpRpcRsResultGPDesc::~GpRpcRsResultGPDesc (void) noexcept
{
}

void    GpRpcRsResultGPDesc::_SReflectCollectProps (GpReflectProp::SmallVecVal& aPropsOut)
{
    PROP(code);
    PROP(msg);
    PROP(items);
}

}// namespace GPlatform
