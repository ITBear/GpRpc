#pragma once

#include "GpRpcRsResultIfDesc.hpp"
#include <any>

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcRsIfDesc: public GpReflectObject
{
public:
    CLASS_DD(GpRpcRsIfDesc)
    REFLECT_DECLARE("d8485e07-ef56-4315-aa0e-763ce6ff5895"_uuid)

public:
                                        GpRpcRsIfDesc   (void) noexcept {}
    explicit                            GpRpcRsIfDesc   (const GpRpcRsIfDesc& aDesc) noexcept: GpReflectObject(aDesc) {}
    explicit                            GpRpcRsIfDesc   (GpRpcRsIfDesc&& aDesc) noexcept: GpReflectObject(std::move(aDesc)) {}
    virtual                             ~GpRpcRsIfDesc  (void) noexcept override {}

    virtual GpRpcRsResultIfDesc::CSP    Result          (void) const;
    virtual GpRpcRsResultIfDesc::SP     Result          (void);
    virtual void                        SetResult       (GpRpcRsResultIfDesc::SP aResult);

    virtual std::any                    Payload         (void) const;
    virtual std::any                    Payload         (void);
    virtual void                        SetPayload      (std::any aAny);
};

}//namespace GPlatform::RPC
