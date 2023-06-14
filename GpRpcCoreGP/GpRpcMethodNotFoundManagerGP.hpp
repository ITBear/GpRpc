#pragma once

#include "GpRpcMethodsManagerGP.hpp"

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcMethodNotFoundManagerGP final: public GpRpcMethodsManagerGP
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodNotFoundManagerGP)
    CLASS_DD(GpRpcMethodNotFoundManagerGP)

public:
                                    GpRpcMethodNotFoundManagerGP    (void) noexcept;
    virtual                         ~GpRpcMethodNotFoundManagerGP   (void) noexcept override final;

    virtual GpRpcRsIfDesc::SP       NewDefaultRs                    (void) const override final;

protected:
    virtual void                    OnInit                          (void) override final;
};

}//namespace GPlatform
