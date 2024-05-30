#include "GpRpcVoidDesc.hpp"

#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpReflection/GpReflectUtils.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcVoidDesc, GP_MODULE_UUID)

GpRpcVoidDesc::~GpRpcVoidDesc (void) noexcept
{
}

void    GpRpcVoidDesc::_SReflectCollectProps ([[maybe_unused]] GpReflectProp::SmallVecVal& aPropsOut)
{
}

}// namespace GPlatform
