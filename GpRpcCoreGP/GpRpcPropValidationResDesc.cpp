#include "GpRpcPropValidationResDesc.hpp"
#include "../../GpCore2/GpReflection/GpReflectManager.hpp"

namespace GPlatform {

REFLECT_IMPLEMENT(GpRpcPropValidationResDesc, GP_MODULE_UUID)

GpRpcPropValidationResDesc::~GpRpcPropValidationResDesc (void) noexcept
{
}

void    GpRpcPropValidationResDesc::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut)
{
    PROP(name);
    PROP(error);
    PROP(is_valid);
}

}//namespace GPlatform
