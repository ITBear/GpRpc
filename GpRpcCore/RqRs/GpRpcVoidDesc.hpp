#pragma once

#include "../GpRpcCore_global.hpp"
#include "../../../GpCore2/GpUtils/Macro/GpMacroClass.hpp"
#include "../../../GpCore2/GpUtils/Types/Containers/GpContainersT.hpp"
#include "../../../GpCore2/GpUtils/Types/Containers/GpAny.hpp"
#include "../../../GpCore2/GpReflection/GpReflectObject.hpp"

namespace GPlatform {

class GP_RPC_CORE_API GpRpcVoidDesc final: public GpReflectObject
{
public:
    CLASS_DD(GpRpcVoidDesc)
    REFLECT_DECLARE(u8"f38857d3-6c29-414b-9761-4128391a2a33"_uuid)

public:
                        GpRpcVoidDesc   (void) noexcept = default;
    inline              GpRpcVoidDesc   (const GpRpcVoidDesc& aDesc) noexcept;
    inline              GpRpcVoidDesc   (GpRpcVoidDesc&& aDesc) noexcept;
    virtual             ~GpRpcVoidDesc  (void) noexcept override final;
};

GpRpcVoidDesc::GpRpcVoidDesc (const GpRpcVoidDesc& aDesc) noexcept:
GpReflectObject(aDesc)
{
}

GpRpcVoidDesc::GpRpcVoidDesc (GpRpcVoidDesc&& aDesc) noexcept:
GpReflectObject(std::move(aDesc))
{
}

}//namespace GPlatform
