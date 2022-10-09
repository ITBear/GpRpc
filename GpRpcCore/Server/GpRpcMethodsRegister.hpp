#pragma once

#include "GpRpcMethodFactory.hpp"

namespace GPlatform::RPC {

class GpRpcMethodsManager;

class GP_RPC_CORE_API GpRpcMethodsRegister
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodsRegister)
    CLASS_DD(GpRpcMethodsRegister)

protected:
                                GpRpcMethodsRegister    (void) noexcept {}

public:
    virtual                     ~GpRpcMethodsRegister   (void) noexcept {}

    virtual void                OnInit                  (GpRpcMethodsManager& aRpcMethodsManager) = 0;
};

}//namespace GPlatform::RPC
