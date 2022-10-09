#include "GpRpcRqJsonDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRqJsonDesc, GP_MODULE_UUID)

GpRpcRqJsonDesc::~GpRpcRqJsonDesc (void) noexcept
{
}

std::string_view    GpRpcRqJsonDesc::Method (void) const
{
    return method;
}

void    GpRpcRqJsonDesc::SetMethod (std::string_view aMethod)
{
    method = aMethod;
}

void    GpRpcRqJsonDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(jsonrpc);
    PROP(id);
    PROP(method);
}

}//namespace GPlatform::RPC
