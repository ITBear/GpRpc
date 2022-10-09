#include "GpRpcMethodsManagersGroup.hpp"

namespace GPlatform::RPC {

GpRpcMethodsManagersGroup::~GpRpcMethodsManagersGroup (void) noexcept
{
}

void    GpRpcMethodsManagersGroup::RegisterApiMethodsManager (GpRpcMethodsManager::SP aApiMethodsManager)
{
    aApiMethodsManager.V().Init();

    aApiMethodsManager.V().Factories().Process
    ([&](auto& aElements)
    {
        for (auto& e: aElements)
        {
            iApiManagers.Register
            (
                std::get<0>(e),
                std::tuple<GpRpcMethodsManager::SP, GpRpcMethodFactory::SP>{aApiMethodsManager, std::get<1>(e)}
            );
        }
    });
}

GpRpcMethodsManagersGroup::ManagerAndMethodT    GpRpcMethodsManagersGroup::FindManagerAndMethod (std::string_view aMethodName) const
{
    auto res = iApiManagers.FindOpt(aMethodName);

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
}

GpRpcMethodsManager::SP GpRpcMethodsManagersGroup::MethodNotFoundManager (void)
{
    return iApiMethodNotFoundManager;
}

void    GpRpcMethodsManagersGroup::ThrowMethodNotFound (std::string_view aMethodName)
{
    iApiMethodNotFoundThrower.V().Throw(aMethodName);
}

}//namespace GPlatform::RPC
