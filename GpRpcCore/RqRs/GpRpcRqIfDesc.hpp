#pragma once

#include "../GpRpcCore_global.hpp"

namespace GPlatform::RPC {

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

    virtual std::any            Payload         (void) const;
    virtual std::any            Payload         (void);
    virtual void                SetPayload      (std::any aAny);
};

}//GPlatform::RPC
