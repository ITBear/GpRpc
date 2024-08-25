#pragma once

#include <GpRpc/GpRpcCoreGP/GpRpcCoreGP_global.hpp>
#include <GpCore2/GpReflection/GpReflectObject.hpp>
#include <GpCore2/GpReflection/GpReflectUtils.hpp>

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcRsResultGPDesc final: public GpReflectObject
{
public:
    CLASS_DD(GpRpcRsResultGPDesc)
    REFLECT_DECLARE("ae323226-0b92-4010-8582-317185e8885f"_uuid)

public:
    using ItemT = GpReflectObject;

public:
                        GpRpcRsResultGPDesc     (void) noexcept = default;
    inline              GpRpcRsResultGPDesc     (const GpRpcRsResultGPDesc& aDesc);
    inline              GpRpcRsResultGPDesc     (GpRpcRsResultGPDesc&& aDesc) noexcept;
    inline              GpRpcRsResultGPDesc     (std::string        aCode,
                                                 std::string        aMsg,
                                                 ItemT::C::Vec::SP  aItems) noexcept;
    virtual             ~GpRpcRsResultGPDesc    (void) noexcept override;

public:
    std::string         code    = "OK";
    std::string         msg;
    ItemT::C::Vec::SP   items;
};

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc (const GpRpcRsResultGPDesc& aDesc):
GpReflectObject{aDesc},
code {GpReflectUtils::SCopyValue(aDesc.code)},
msg  {GpReflectUtils::SCopyValue(aDesc.msg)},
items{GpReflectUtils::SCopyValue(aDesc.items)}
{
}

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc (GpRpcRsResultGPDesc&& aDesc) noexcept:
GpReflectObject{std::move(aDesc)},
code {std::move(aDesc.code)},
msg  {std::move(aDesc.msg)},
items{std::move(aDesc.items)}
{
}

GpRpcRsResultGPDesc::GpRpcRsResultGPDesc
(
    std::string         aCode,
    std::string         aMsg,
    ItemT::C::Vec::SP   aItems
) noexcept:
code {std::move(aCode)},
msg  {std::move(aMsg)},
items{std::move(aItems)}
{
}

}// namespace GPlatform
