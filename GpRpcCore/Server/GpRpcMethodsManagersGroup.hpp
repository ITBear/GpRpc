#pragma once

#include "GpRpcMethodsManager.hpp"
#include "GpRpcMethodNotFoundThrower.hpp"

namespace GPlatform {

class GP_RPC_CORE_API GpRpcMethodsManagersGroup
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodsManagersGroup)
    CLASS_DD(GpRpcMethodsManagersGroup)

    using ManagerAndMethodT = std::tuple<GpRpcMethodsManager::SP, GpRpcMethod::SP>;
    using ApiManagerT       = std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>;
    using ApiManagersT      = GpDictionary<std::u8string, ApiManagerT>;

public:
    inline                          GpRpcMethodsManagersGroup   (GpRpcMethodsManager::SP        aApiMethodNotFoundManager,
                                                                 GpRpcMethodNotFoundThrower::SP aApiMethodNotFoundThrower) noexcept;
    virtual                         ~GpRpcMethodsManagersGroup  (void) noexcept;

    void                            Register                    (GpRpcMethodsManager::SP aApiMethodsManager);
    void                            RegisterEmptyMethodName     (GpRpcMethodsManager::SP aApiMethodsManager);
    ManagerAndMethodT               Find                        (const std::optional<std::u8string>& aMethodName) const;

    GpRpcMethodsManager::SP         MethodNotFoundManager       (void);
    void                            ThrowMethodNotFound         (const std::optional<std::u8string>& aMethodName);

private:
    GpRpcMethodsManager::SP         iApiMethodNotFoundManager;
    GpRpcMethodNotFoundThrower::SP  iApiMethodNotFoundThrower;
    ApiManagersT                    iApiManagers;
    ApiManagerT                     iApiManagerEmptyMethodName;
};

GpRpcMethodsManagersGroup::GpRpcMethodsManagersGroup
(
    GpRpcMethodsManager::SP         aApiMethodNotFoundManager,
    GpRpcMethodNotFoundThrower::SP  aApiMethodNotFoundThrower
) noexcept:
iApiMethodNotFoundManager(std::move(aApiMethodNotFoundManager)),
iApiMethodNotFoundThrower(std::move(aApiMethodNotFoundThrower))
{
}

}//namespace GPlatform
