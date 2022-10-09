#pragma once

#include "GpRpcMethodsManager.hpp"
#include "GpRpcMethodNotFoundThrower.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcMethodsManagersGroup
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodsManagersGroup)
    CLASS_DD(GpRpcMethodsManagersGroup)

    using ManagerAndMethodT = std::tuple<GpRpcMethodsManager::SP, GpRpcMethod::SP>;
    using ApiManagersT      = GpElementsCatalog<std::string_view, std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>>;

public:
    inline                          GpRpcMethodsManagersGroup   (GpRpcMethodsManager::SP        aApiMethodNotFoundManager,
                                                                 GpRpcMethodNotFoundThrower::SP aApiMethodNotFoundThrower) noexcept;
    virtual                         ~GpRpcMethodsManagersGroup  (void) noexcept;

    void                            RegisterApiMethodsManager   (GpRpcMethodsManager::SP aApiMethodsManager);
    ManagerAndMethodT               FindManagerAndMethod        (std::string_view aMethodName) const;

    GpRpcMethodsManager::SP         MethodNotFoundManager       (void);
    void                            ThrowMethodNotFound         (std::string_view aMethodName);

private:
    GpRpcMethodsManager::SP         iApiMethodNotFoundManager;
    GpRpcMethodNotFoundThrower::SP  iApiMethodNotFoundThrower;
    ApiManagersT                    iApiManagers;
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

}//namespace GPlatform::RPC
