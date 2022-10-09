#pragma once

#include "../RqRs/GpRpcRqRs.hpp"

namespace GPlatform::RPC {

class GpRpcMethod
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethod)
    CLASS_DD(GpRpcMethod)

public:
                                            GpRpcMethod     (void) noexcept {}
    virtual                                 ~GpRpcMethod    (void) noexcept {}

    virtual GpRpcRsIfDesc::SP               Process         (GpRpcRqIfDesc& aRq) = 0;
    virtual const GpReflectModel&           RqReflectModel  (void) const noexcept = 0;
    virtual const GpReflectModel&           RsReflectModel  (void) const noexcept = 0;
    virtual std::string_view                MethodName      (void) const noexcept = 0;
};

}//namespace GPlatform::RPC
