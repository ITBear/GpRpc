#include "GpRpcRsIfDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRsIfDesc, GP_MODULE_UUID)

GpRpcRsResultIfDesc::CSP    GpRpcRsIfDesc::Result (void) const
{
    THROW_GP("Need to be overridden"_sv);
}

GpRpcRsResultIfDesc::SP GpRpcRsIfDesc::Result (void)
{
    THROW_GP("Need to be overridden"_sv);
}

void    GpRpcRsIfDesc::SetResult (GpRpcRsResultIfDesc::SP /*aResult*/)
{
    THROW_GP("Need to be overridden"_sv);
}

std::any    GpRpcRsIfDesc::Payload (void) const
{
    THROW_GP("Need to be overridden"_sv);
}

std::any    GpRpcRsIfDesc::Payload (void)
{
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpRpcRsIfDesc::SetPayload (std::any /*aAny*/)
{
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpRpcRsIfDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::RPC
