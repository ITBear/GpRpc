#include "GpRpcRsJsonDesc.hpp"

#include <GpCore2/GpReflection/GpReflectManager.hpp>

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsJsonDesc, GP_MODULE_UUID)

GpRpcRsJsonDesc::~GpRpcRsJsonDesc (void) noexcept
{
}

GpReflectObject::CSP    GpRpcRsJsonDesc::Result (void) const
{
    return error;
}

GpReflectObject::SP GpRpcRsJsonDesc::Result (void)
{
    return error;
}

void    GpRpcRsJsonDesc::SetResult (GpReflectObject::SP aResult)
{
    error = GpReflectManager::SCastSP<GpRpcRsResultJsonDesc::SP>(aResult);
}

void    GpRpcRsJsonDesc::_SReflectCollectProps (GpReflectProp::SmallVecVal& aPropsOut)
{
    PROP(jsonrpc);
    PROP(id);
    PROP(error);
}

}// namespace GPlatform
