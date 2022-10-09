#pragma once

#include "GpRpcMethodGP.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcMethodsManagerGP: public GpRpcMethodsManager
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodsManagerGP)
    CLASS_DD(GpRpcMethodsManagerGP)

protected:
                                    GpRpcMethodsManagerGP       (void) noexcept;

public:
    virtual                         ~GpRpcMethodsManagerGP  (void) noexcept;

    void                            Init                    (void);

    void                            Register                (GpRpcMethodFactory::SP aFactory);
    void                            Register                (GpRpcMethodsRegister& aApiMethodsRegister);
    MethodFactoriesT&               Factories               (void) noexcept {return iFactories;}

    virtual GpRpcRsIfDesc::SP       NewDefaultRs            (void) const override = 0;
    virtual GpRpcRsResultIfDesc::SP GenResultOK             (void) const override final;
    virtual GpRpcRsResultIfDesc::SP GenResultEx             (const std::exception& e) const override final;
    virtual GpRpcRsResultIfDesc::SP GenResultExUnknown      (void) const override final;
    virtual GpRpcRsResultIfDesc::SP CallAndCatch            (std::function<void()> aFn) const override final;

protected:
    virtual void                    OnInit                  (void) override = 0;

protected:
    MethodFactoriesT                iFactories;
};

}//namespace GPlatform::RPC
