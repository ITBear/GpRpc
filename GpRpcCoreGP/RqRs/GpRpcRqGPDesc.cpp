#include "GpRpcRqGPDesc.hpp"
#include "../../../GpCore2/GpReflection/GpReflectManager.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRqGPDesc, GP_MODULE_UUID)

GpRpcRqGPDesc::~GpRpcRqGPDesc (void) noexcept
{
}

std::u8string_view  GpRpcRqGPDesc::Method (void) const
{
    return method;
}

void    GpRpcRqGPDesc::SetMethod (std::u8string_view aMethod)
{
    method = aMethod;
}

void    GpRpcRqGPDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(method);
    PROP(sid);
}

}//namespace GPlatform
