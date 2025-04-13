#include <GpRpc/GpRpcCore/RqRs/GpRpcRsIfDesc.hpp>
#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpReflection/GpReflectUtils.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsIfDesc, GP_MODULE_UUID)

GpReflectObject::CSP    GpRpcRsIfDesc::Result (void) const
{
    THROW("Need to be overridden");
}

GpReflectObject::SP GpRpcRsIfDesc::Result (void)
{
    THROW("Need to be overridden");
}

void    GpRpcRsIfDesc::SetResult ([[maybe_unused]] GpReflectObject::SP aResult)
{
    THROW("Need to be overridden");
}

GpAny   GpRpcRsIfDesc::Payload (void) const
{
    THROW("Need to be overridden");
}

GpAny   GpRpcRsIfDesc::Payload (void)
{
    THROW("Need to be overridden");
}

void    GpRpcRsIfDesc::SetPayload ([[maybe_unused]] GpAny& aPayload)
{
    THROW("Need to be overridden");
}

void    GpRpcRsIfDesc::_SReflectCollectProps ([[maybe_unused]] GpReflectProp::SmallVecVal& aPropsOut)
{
}

}// namespace GPlatform
