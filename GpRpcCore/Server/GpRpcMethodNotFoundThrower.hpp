#pragma once

#include "../GpRpcCore_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcMethodNotFoundThrower
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodNotFoundThrower)
    CLASS_DD(GpRpcMethodNotFoundThrower)

protected:
                                GpRpcMethodNotFoundThrower  (void) noexcept = default;

public:
    virtual                     ~GpRpcMethodNotFoundThrower (void) noexcept = default;

    virtual void                Throw                       (std::string_view aMethodName) const = 0;
};

}//namespace GPlatform::RPC
