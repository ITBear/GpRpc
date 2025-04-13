#include <GpRpc/GpRpcCore/RqRs/GpRpcRqIfDesc.hpp>
#include <GpCore2/GpReflection/GpReflectManager.hpp>
#include <GpCore2/GpReflection/GpReflectUtils.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRqIfDesc, GP_MODULE_UUID)

std::string_view    GpRpcRqIfDesc::Method (void) const
{
    THROW("Need to be overridden");
}

void    GpRpcRqIfDesc::SetMethod ([[maybe_unused]] std::string_view aMethod)
{
    THROW("Need to be overridden");
}

GpAny   GpRpcRqIfDesc::Payload (void) const
{
    THROW("Need to be overridden");
}

GpAny   GpRpcRqIfDesc::Payload (void)
{
    THROW("Need to be overridden");
}

void    GpRpcRqIfDesc::SetPayload ([[maybe_unused]] GpAny& aPayload)
{
    THROW("Need to be overridden");
}

void    GpRpcRqIfDesc::_SReflectCollectProps ([[maybe_unused]] GpReflectProp::SmallVecVal& aPropsOut)
{
}

}// namespace GPlatform
