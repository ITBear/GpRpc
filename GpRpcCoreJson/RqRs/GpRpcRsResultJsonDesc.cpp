#include "GpRpcRsResultJsonDesc.hpp"

#include <GpCore2/GpReflection/GpReflectManager.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsResultJsonDesc, GP_MODULE_UUID)

GpRpcRsResultJsonDesc::~GpRpcRsResultJsonDesc (void) noexcept
{
}

void    GpRpcRsResultJsonDesc::_SReflectCollectProps ([[maybe_unused]] GpReflectProp::SmallVecVal& aPropsOut)
{
    PROP(code);
    PROP(message);
}

}// namespace GPlatform
