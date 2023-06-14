#include "GpRpcRsIfDesc.hpp"
#include "../../../GpCore2/GpReflection/GpReflectManager.hpp"
#include "../../../GpCore2/GpReflection/GpReflectUtils.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsIfDesc, GP_MODULE_UUID)

GpReflectObject::CSP    GpRpcRsIfDesc::Result (void) const
{
    THROW_GP(u8"Need to be overridden"_sv);
}

GpReflectObject::SP GpRpcRsIfDesc::Result (void)
{
    THROW_GP(u8"Need to be overridden"_sv);
}

void    GpRpcRsIfDesc::SetResult (GpReflectObject::SP /*aResult*/)
{
    THROW_GP(u8"Need to be overridden"_sv);
}

GpAny   GpRpcRsIfDesc::Payload (void) const
{
    THROW_GP(u8"Need to be overridden"_sv);
}

GpAny   GpRpcRsIfDesc::Payload (void)
{
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpRpcRsIfDesc::SetPayload (GpAny& /*aAny*/)
{
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpRpcRsIfDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform
