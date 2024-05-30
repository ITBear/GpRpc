#include "GpRpcRqGPDesc.hpp"

#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpReflection/GpReflectPropUtils.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRqGPDesc, GP_MODULE_UUID)

GpRpcRqGPDesc::~GpRpcRqGPDesc (void) noexcept
{
}

std::string_view    GpRpcRqGPDesc::Method (void) const
{
    return method;
}

void    GpRpcRqGPDesc::SetMethod (std::string_view aMethod)
{
    method = aMethod;
}

void    GpRpcRqGPDesc::_SReflectCollectProps (GpReflectProp::SmallVecVal& aPropsOut)
{
    PROP(method);
    PROP(sid);
}

}// namespace GPlatform
