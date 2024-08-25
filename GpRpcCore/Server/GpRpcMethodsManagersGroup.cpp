#include <GpRpc/GpRpcCore/Server/GpRpcMethodsManagersGroup.hpp>

namespace GPlatform {

GpRpcMethodsManagersGroup::GpRpcMethodsManagersGroup
(
    GpRpcMethodsManager::SP         aApiMethodNotFoundManager,
    GpRpcMethodNotFoundThrower::SP  aApiMethodNotFoundThrower
) noexcept:
iApiMethodNotFoundManager(std::move(aApiMethodNotFoundManager)),
iApiMethodNotFoundThrower(std::move(aApiMethodNotFoundThrower))
{
}

GpRpcMethodsManagersGroup::~GpRpcMethodsManagersGroup (void) noexcept
{
}

void    GpRpcMethodsManagersGroup::Register (GpRpcMethodsManager::SP aApiMethodsManager)
{
    aApiMethodsManager->Init();

    aApiMethodsManager->Factories().ProcessContainer
    (
        [&](auto& aElements)
        {
            for (auto&[methodName, methodFactory]: aElements)
            {
                iApiManagers.SetOrUpdate
                (
                    methodName,
                    std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>
                    {
                        aApiMethodsManager,
                        methodFactory
                    }
                );
            }
        }
    );
}

void    GpRpcMethodsManagersGroup::RegisterEmptyMethodNameManager (GpRpcMethodsManager::SP aApiMethodsManager)
{
    aApiMethodsManager.V().Init();

    aApiMethodsManager.V().Factories().ProcessContainer
    (
        [&](auto& aElements)
        {
            for (auto&[methodName, methodFactory]: aElements)
            {
                iEmptyManagerAndMethodFactory = std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>
                {
                    aApiMethodsManager,
                    methodFactory
                };

                break;
            }
        }
    );
}

GpRpcMethodsManagersGroup::ManagerAndMethodT    GpRpcMethodsManagersGroup::Find (std::string_view aMethodName) const
{
    if (!aMethodName.empty())
    {
        auto managerAndMethodFactoryOpt = iApiManagers.GetOpt(aMethodName);

        if (!managerAndMethodFactoryOpt.has_value()) [[unlikely]]
        {
            return
            {
                GpRpcMethodsManager::SP::SNull(),
                GpRpcMethod::SP::SNull()
            };
        }

        auto& [manager, methodFactory] = managerAndMethodFactoryOpt.value();

        return ManagerAndMethodT
        {
            manager,
            methodFactory->NewInstance()
        };
    } else
    {
        return ManagerAndMethodT
        {
            std::get<0>(iEmptyManagerAndMethodFactory),
            std::get<1>(iEmptyManagerAndMethodFactory).V().NewInstance()
        };
    }
}

GpRpcMethodsManager::SP GpRpcMethodsManagersGroup::MethodNotFoundManager (void)
{
    return iApiMethodNotFoundManager;
}

void    GpRpcMethodsManagersGroup::ThrowMethodNotFound (std::string_view aMethodName)
{
    if (!aMethodName.empty())
    {
        iApiMethodNotFoundThrower.V().Throw(aMethodName);
    } else
    {
        iApiMethodNotFoundThrower.V().Throw("Unknown method (RQ method name is not set");
    }
}

}// namespace GPlatform
