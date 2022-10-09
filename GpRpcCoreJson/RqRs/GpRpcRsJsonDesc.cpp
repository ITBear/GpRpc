#include "GpRpcRsJsonDesc.hpp"

namespace GPlatform::RPC {

REFLECT_IMPLEMENT(GpRpcRsJsonDesc, GP_MODULE_UUID)

GpRpcRsJsonDesc::~GpRpcRsJsonDesc (void) noexcept
{
}

GpRpcRsResultIfDesc::CSP    GpRpcRsJsonDesc::Result (void) const
{
    return error;
}

GpRpcRsResultIfDesc::SP GpRpcRsJsonDesc::Result (void)
{
    return error;
}

void    GpRpcRsJsonDesc::SetResult (GpRpcRsResultIfDesc::SP aResult)
{
    error = GpReflectManager::SCastSP<GpRpcRsResultJsonDesc::SP>(aResult);
}

void    GpRpcRsJsonDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(jsonrpc);
    PROP(id);
    PROP(error);
}

}//namespace GPlatform::RPC
