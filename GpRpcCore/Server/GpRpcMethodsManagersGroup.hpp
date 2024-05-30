#pragma once

#include "GpRpcMethodsManager.hpp"
#include "GpRpcMethodNotFoundThrower.hpp"

namespace GPlatform {

class GP_RPC_CORE_API GpRpcMethodsManagersGroup
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodsManagersGroup)
    CLASS_DD(GpRpcMethodsManagersGroup)

    TAG_SET(THREAD_SAFE)

    using ManagerAndMethodT         = std::tuple<GpRpcMethodsManager::SP, GpRpcMethod::SP>;
    using ManagerAndMethodFactoryT  = std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>;
    using ApiManagersT              = GpDictionary<boost::container::flat_map<std::string/*method name*/, ManagerAndMethodFactoryT, std::less<>>>;

public:
                                    GpRpcMethodsManagersGroup       (GpRpcMethodsManager::SP        aApiMethodNotFoundManager,
                                                                     GpRpcMethodNotFoundThrower::SP aApiMethodNotFoundThrower) noexcept;
    virtual                         ~GpRpcMethodsManagersGroup      (void) noexcept;

    void                            Register                        (GpRpcMethodsManager::SP aApiMethodsManager);
    void                            RegisterEmptyMethodNameManager  (GpRpcMethodsManager::SP aApiMethodsManager);
    ManagerAndMethodT               Find                            (std::string_view aMethodName) const;

    GpRpcMethodsManager::SP         MethodNotFoundManager           (void);
    void                            ThrowMethodNotFound             (std::string_view aMethodName);

private:
    GpRpcMethodsManager::SP         iApiMethodNotFoundManager;
    GpRpcMethodNotFoundThrower::SP  iApiMethodNotFoundThrower;
    ApiManagersT                    iApiManagers;
    ManagerAndMethodFactoryT        iEmptyManagerAndMethodFactory;
};

}// namespace GPlatform
