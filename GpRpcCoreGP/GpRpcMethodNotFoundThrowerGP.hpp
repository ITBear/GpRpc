#pragma once

#include "GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcMethodNotFoundThrowerGP final: public GpRpcMethodNotFoundThrower
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodNotFoundThrowerGP)
    CLASS_DD(GpRpcMethodNotFoundThrowerGP)

public:
                                GpRpcMethodNotFoundThrowerGP    (void) noexcept = default;
    virtual                     ~GpRpcMethodNotFoundThrowerGP   (void) noexcept override final = default;

    virtual void                Throw                           (std::string_view aMethodName) const override final;
};

}//namespace GPlatform::RPC
