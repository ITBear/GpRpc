#include "GpRpcRqIfDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRqIfDesc, GP_MODULE_UUID)

std::string_view    GpRpcRqIfDesc::Method (void) const
{
    THROW_GP("Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::SetMethod (std::string_view /*aMethod*/)
{
    THROW_GP("Need to be overridden"_sv);
}

std::any    GpRpcRqIfDesc::Payload (void) const
{
    THROW_GP("Need to be overridden"_sv);
}

std::any    GpRpcRqIfDesc::Payload (void)
{
    THROW_GP("Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::SetPayload (std::any /*aAny*/)
{
    THROW_GP("Need to be overridden"_sv);
}

void    GpRpcRqIfDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::RPC
