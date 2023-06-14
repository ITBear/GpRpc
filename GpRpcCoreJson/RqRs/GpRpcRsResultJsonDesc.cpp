#include "GpRpcRsResultJsonDesc.hpp"
#include "../../GpCore2/GpReflection/GpReflectManager.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcRsResultJsonDesc, GP_MODULE_UUID)

GpRpcRsResultJsonDesc::~GpRpcRsResultJsonDesc (void) noexcept
{
}

void    GpRpcRsResultJsonDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(code);
    PROP(message);
}

}//namespace GPlatform
