#pragma once

#include <GpRpc/GpRpcCore/GpRpcCore_global.hpp>
#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Strings/GpStringOps.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpDictionary.hpp>
#include <GpRpc/GpRpcCore/Server/GpRpcMethodFactory.hpp>

namespace GPlatform {

class GP_RPC_CORE_API GpRpcMethodsManager
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodsManager)
    CLASS_DD(GpRpcMethodsManager)

    TAG_SET(THREAD_SAFE)

    using MethodFactoriesT = GpDictionary<boost::container::flat_map<std::string, GpRpcMethodFactory::SP, std::less<>>>;

protected:
                                GpRpcMethodsManager     (void) noexcept;

public:
    virtual                     ~GpRpcMethodsManager    (void) noexcept;

    void                        Init                    (void);

    void                        Register                (GpRpcMethodFactory::SP aFactory);
    MethodFactoriesT&           Factories               (void) noexcept {return iFactories;}

    virtual GpRpcRsIfDesc::SP   NewDefaultRs            (void) const = 0;
    virtual GpReflectObject::SP GenResultOK             (void) const = 0;
    virtual GpReflectObject::SP GenResultEx             (const std::exception& e) const = 0;
    virtual GpReflectObject::SP GenResultExUnknown      (void) const = 0;
    virtual GpReflectObject::SP CallAndCatch            (std::function<void()> aFn) const = 0;

protected:
    virtual void                OnInit                  (void) = 0;

private:
    MethodFactoriesT            iFactories;
};

}// namespace GPlatform
