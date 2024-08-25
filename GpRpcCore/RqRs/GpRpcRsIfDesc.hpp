#pragma once

#include <GpRpc/GpRpcCore/GpRpcCore_global.hpp>
#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpAny.hpp>
#include <GpCore2/GpReflection/GpReflectObject.hpp>

namespace GPlatform {

class GP_RPC_CORE_API GpRpcRsIfDesc: public GpReflectObject
{
public:
    CLASS_DD(GpRpcRsIfDesc)
    REFLECT_DECLARE("d8485e07-ef56-4315-aa0e-763ce6ff5895"_uuid)

public:
                                    GpRpcRsIfDesc   (void) noexcept {}
    explicit                        GpRpcRsIfDesc   (const GpRpcRsIfDesc& aDesc) noexcept: GpReflectObject(aDesc) {}
    explicit                        GpRpcRsIfDesc   (GpRpcRsIfDesc&& aDesc) noexcept: GpReflectObject(std::move(aDesc)) {}
    virtual                         ~GpRpcRsIfDesc  (void) noexcept override {}

    virtual GpReflectObject::CSP    Result          (void) const;
    virtual GpReflectObject::SP     Result          (void);
    virtual void                    SetResult       (GpReflectObject::SP aResult);

    virtual GpAny                   Payload         (void) const;
    virtual GpAny                   Payload         (void);
    virtual void                    SetPayload      (GpAny& aPayload);
};

}// namespace GPlatform
