#pragma once

#include <GpRpc/GpRpcCore/GpRpcCore_global.hpp>
#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpAny.hpp>
#include <GpCore2/GpReflection/GpReflectObject.hpp>

namespace GPlatform {

class GP_RPC_CORE_API GpRpcRqIfDesc: public GpReflectObject
{
public:
    CLASS_DD(GpRpcRqIfDesc)
    REFLECT_DECLARE("6f7f6db1-67f0-4425-97ee-6e0eecbc3e2d"_uuid)

public:
                                GpRpcRqIfDesc   (void) noexcept {}
    explicit                    GpRpcRqIfDesc   (const GpRpcRqIfDesc& aDesc) noexcept: GpReflectObject(aDesc) {}
    explicit                    GpRpcRqIfDesc   (GpRpcRqIfDesc&& aDesc) noexcept: GpReflectObject(std::move(aDesc)) {}
    virtual                     ~GpRpcRqIfDesc  (void) noexcept override{}

    virtual std::string_view    Method          (void) const;
    virtual void                SetMethod       (std::string_view aMethod);

    virtual GpAny               Payload         (void) const;
    virtual GpAny               Payload         (void);
    virtual void                SetPayload      (GpAny& aPayload);
};

}// namespace GPlatform
