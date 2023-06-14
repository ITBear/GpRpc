#include "GpRpcMethodsManagersGroup.hpp"

namespace GPlatform {

GpRpcMethodsManagersGroup::~GpRpcMethodsManagersGroup (void) noexcept
{
}

void    GpRpcMethodsManagersGroup::Register (GpRpcMethodsManager::SP aApiMethodsManager)
{
    aApiMethodsManager.V().Init();

    aApiMethodsManager.V().Factories().Process
    ([&](auto& aElements)
    {
        for (auto& e: aElements)
        {
            iApiManagers.Set
            (
                std::get<0>(e),
                std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>{aApiMethodsManager, std::get<1>(e)}
            );
        }
    });
}

void    GpRpcMethodsManagersGroup::RegisterEmptyMethodName (GpRpcMethodsManager::SP aApiMethodsManager)
{
    aApiMethodsManager.V().Init();

    aApiMethodsManager.V().Factories().Process
    ([&](auto& aElements)
    {
        for (auto& e: aElements)
        {
            iApiManagerEmptyMethodName = std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>{aApiMethodsManager, std::get<1>(e)};
            break;
        }
    });
}

GpRpcMethodsManagersGroup::ManagerAndMethodT    GpRpcMethodsManagersGroup::Find (const std::optional<std::u8string>& aMethodName) const
{
    if (aMethodName.has_value())
    {
        auto res = iApiManagers.GetOpt(aMethodName.value());

        if (!res.has_value())
        {
            return
            {
                GpRpcMethodsManager::SP::SNull(),
                GpRpcMethod::SP::SNull()
            };
        }

        auto& v = res.value().get();

        return {std::get<0>(v), std::get<1>(v).V().NewInstance()};
    } else
    {
        return
        {
            std::get<0>(iApiManagerEmptyMethodName),
            std::get<1>(iApiManagerEmptyMethodName).V().NewInstance()
        };
    }
}

GpRpcMethodsManager::SP GpRpcMethodsManagersGroup::MethodNotFoundManager (void)
{
    return iApiMethodNotFoundManager;
}

void    GpRpcMethodsManagersGroup::ThrowMethodNotFound (const std::optional<std::u8string>& aMethodName)
{
    if (aMethodName.has_value())
    {
        iApiMethodNotFoundThrower.V().Throw(aMethodName.value());
    } else
    {
        iApiMethodNotFoundThrower.V().Throw(u8"Unknown method (RQ method name is not set");
    }
}

}//namespace GPlatform
