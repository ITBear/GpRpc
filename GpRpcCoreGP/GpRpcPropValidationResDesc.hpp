#pragma once

#include "GpRpcCoreGP_global.hpp"
#include "../../GpCore2/GpReflection/GpReflectUtils.hpp"

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcPropValidationResDesc final: public GpReflectObject
{
public:
    CLASS_DD(GpRpcPropValidationResDesc)
    REFLECT_DECLARE(u8"36371ddf-1cc6-4938-9b6b-f7c32672523b"_uuid)

public:
                        GpRpcPropValidationResDesc  (void) noexcept = default;
    inline              GpRpcPropValidationResDesc  (const GpRpcPropValidationResDesc& aDesc);
    inline              GpRpcPropValidationResDesc  (GpRpcPropValidationResDesc&& aDesc) noexcept;
    inline              GpRpcPropValidationResDesc  (std::u8string  aName,
                                                     std::u8string  aError,
                                                     const bool     aIsValid) noexcept;
    virtual             ~GpRpcPropValidationResDesc (void) noexcept override final;

public:
    std::u8string       name;
    std::u8string       error;
    bool                is_valid = false;
};

GpRpcPropValidationResDesc::GpRpcPropValidationResDesc (const GpRpcPropValidationResDesc& aDesc):
GpReflectObject(aDesc),
name    (GpReflectUtils::SCopyValue(aDesc.name)),
error   (GpReflectUtils::SCopyValue(aDesc.error)),
is_valid(GpReflectUtils::SCopyValue(aDesc.is_valid))
{
}

GpRpcPropValidationResDesc::GpRpcPropValidationResDesc (GpRpcPropValidationResDesc&& aDesc) noexcept:
GpReflectObject(std::move(aDesc)),
name    (std::move(aDesc.name)),
error   (std::move(aDesc.error)),
is_valid(std::move(aDesc.is_valid))
{
}

GpRpcPropValidationResDesc::GpRpcPropValidationResDesc
(
    std::u8string   aName,
    std::u8string   aError,
    const bool      aIsValid
) noexcept:
name    (std::move(aName)),
error   (std::move(aError)),
is_valid(std::move(aIsValid))
{
}

}//GPlatform
