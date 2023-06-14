#include "GpRpcRqIfDesc.hpp"
#include "../../../GpCore2/GpReflection/GpReflectManager.hpp"
#include "../../../GpCore2/GpReflection/GpReflectUtils.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRqIfDesc, GP_MODULE_UUID)

std::u8string_view  GpRpcRqIfDesc::Method (void) const
{
    THROW_GP(u8"Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::SetMethod (std::u8string_view /*aMethod*/)
{
    THROW_GP(u8"Need to be overridden"_sv);
}

GpAny   GpRpcRqIfDesc::Payload (void) const
{
    THROW_GP(u8"Need to be overridden"_sv);
}

GpAny   GpRpcRqIfDesc::Payload (void)
{
    THROW_GP(u8"Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::SetPayload (GpAny& /*aAny*/)
{
    THROW_GP(u8"Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform
