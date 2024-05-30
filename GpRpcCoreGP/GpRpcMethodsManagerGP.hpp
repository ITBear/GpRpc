#pragma once

#include "GpRpcCoreGP_global.hpp"
#include "../GpRpcCore/Server/GpRpcMethodsManager.hpp"

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcMethodsManagerGP: public GpRpcMethodsManager
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodsManagerGP)
    CLASS_DD(GpRpcMethodsManagerGP)

protected:
                                GpRpcMethodsManagerGP   (void) noexcept;

public:
    virtual                     ~GpRpcMethodsManagerGP  (void) noexcept;

    virtual GpRpcRsIfDesc::SP   NewDefaultRs            (void) const override = 0;
    virtual GpReflectObject::SP GenResultOK             (void) const override final;
    virtual GpReflectObject::SP GenResultEx             (const std::exception& e) const override final;
    virtual GpReflectObject::SP GenResultExUnknown      (void) const override final;
    virtual GpReflectObject::SP CallAndCatch            (std::function<void()> aFn) const override final;

protected:
    virtual void                OnInit                  (void) override = 0;
};

}// namespace GPlatform
