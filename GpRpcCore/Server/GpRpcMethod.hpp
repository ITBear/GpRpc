#pragma once

#include <GpRpc/GpRpcCore/RqRs/GpRpcRqIfDesc.hpp>
#include <GpRpc/GpRpcCore/RqRs/GpRpcRsIfDesc.hpp>

namespace GPlatform {

class GP_RPC_CORE_API GpRpcMethod
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethod)
    CLASS_DD(GpRpcMethod)

public:
                                    GpRpcMethod     (void) noexcept = default;
    virtual                         ~GpRpcMethod    (void) noexcept;

    virtual GpRpcRsIfDesc::SP       Process         (GpRpcRqIfDesc& aRq) = 0;
    virtual GpReflectModel::CSP     RqReflectModel  (void) const noexcept = 0;
    virtual GpReflectModel::CSP     RsReflectModel  (void) const noexcept = 0;
    virtual std::string_view        MethodName      (void) const noexcept = 0;
};

}// namespace GPlatform
