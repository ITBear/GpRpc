#pragma once

#include "../GpRpcCoreJson_global.hpp"

#include <GpCore2/GpReflection/GpReflectUtils.hpp>

namespace GPlatform {

class GP_RPC_CORE_JSON_API GpRpcRsResultJsonDesc final: public GpReflectObject
{
public:
    CLASS_DD(GpRpcRsResultJsonDesc)
    REFLECT_DECLARE("4297c2ba-8831-47c0-9247-ed50d4dcb3a7"_uuid)

public:
                    GpRpcRsResultJsonDesc   (void) noexcept = default;
    inline          GpRpcRsResultJsonDesc   (const GpRpcRsResultJsonDesc& aDesc);
    inline          GpRpcRsResultJsonDesc   (GpRpcRsResultJsonDesc&& aDesc) noexcept;
    virtual         ~GpRpcRsResultJsonDesc  (void) noexcept override final;

public:
    s_int_64        code    = 0;
    std::string     message;
};

GpRpcRsResultJsonDesc::GpRpcRsResultJsonDesc (const GpRpcRsResultJsonDesc& aDesc):
GpReflectObject(aDesc),
code   (GpReflectUtils::SCopyValue(aDesc.code)),
message(GpReflectUtils::SCopyValue(aDesc.message))
{
}

GpRpcRsResultJsonDesc::GpRpcRsResultJsonDesc (GpRpcRsResultJsonDesc&& aDesc) noexcept:
GpReflectObject(std::move(aDesc)),
code   (std::move(aDesc.code)),
message(std::move(aDesc.message))
{
}

}// namespace GPlatform
