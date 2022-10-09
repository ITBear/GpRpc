#pragma once

#include "GpRpcMethodsRegister.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcMethodsManager
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodsManager)
    CLASS_DD(GpRpcMethodsManager)

    using MethodFactoriesT = GpElementsCatalog<std::string_view, GpRpcMethodFactory::SP>;

protected:
                                    GpRpcMethodsManager     (void) noexcept = default;

public:
    virtual                         ~GpRpcMethodsManager    (void) noexcept = default;

    void                            Init                    (void);

    void                            Register                (GpRpcMethodFactory::SP aFactory);
    void                            Register                (GpRpcMethodsRegister& aApiMethodsRegister);
    MethodFactoriesT&               Factories               (void) noexcept {return iFactories;}

    virtual GpRpcRsIfDesc::SP       NewDefaultRs            (void) const = 0;
    virtual GpRpcRsResultIfDesc::SP GenResultOK             (void) const = 0;
    virtual GpRpcRsResultIfDesc::SP GenResultEx             (const std::exception& e) const = 0;
    virtual GpRpcRsResultIfDesc::SP GenResultExUnknown      (void) const = 0;
    virtual GpRpcRsResultIfDesc::SP CallAndCatch            (std::function<void()> aFn) const = 0;

protected:
    virtual void                    OnInit                  (void) = 0;

protected:
    MethodFactoriesT                iFactories;
};

}//namespace GPlatform::RPC
