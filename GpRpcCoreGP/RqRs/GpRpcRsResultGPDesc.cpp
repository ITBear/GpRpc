#include "GpRpcRsResultGPDesc.hpp"
#include "../../../GpCore2/GpReflection/GpReflectManager.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsResultGPDesc, GP_MODULE_UUID)

GpRpcRsResultGPDesc::~GpRpcRsResultGPDesc (void) noexcept
{
}

void    GpRpcRsResultGPDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(code);
    PROP(msg);
    PROP(items);
}

}//namespace GPlatform
