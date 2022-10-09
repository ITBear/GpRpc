#pragma once

#include "GpRpcMethod.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcMethodFactory
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodFactory)
    CLASS_DD(GpRpcMethodFactory)

public:
                                GpRpcMethodFactory  (std::string_view aMethodName);
    virtual                     ~GpRpcMethodFactory (void) noexcept;

    std::string_view            MethodName          (void) const noexcept {return iMethodName;}

    virtual GpRpcMethod::SP     NewInstance         (void) const = 0;

private:
    const std::string           iMethodName;
};

}//namespace GPlatform::RPC
