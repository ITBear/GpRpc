#include <GpRpc/GpRpcCore/Server/GpRpcMethodsManager.hpp>

namespace GPlatform {

GpRpcMethodsManager::GpRpcMethodsManager (void) noexcept
{
}

GpRpcMethodsManager::~GpRpcMethodsManager (void) noexcept
{
}

void    GpRpcMethodsManager::Init (void)
{
    OnInit();
}

void    GpRpcMethodsManager::Register (GpRpcMethodFactory::SP aFactory)
{
    const auto&         factory     = aFactory.V();
    std::string_view    name        = factory.MethodName();
    const auto[_, state]            = iFactories.FindOrSet(factory.MethodName(), aFactory);

    VERIFY
    (
        state == GpContainerUpdateStatus::INSERT_NEW,
        [name]()
        {
            return fmt::format
            (
                "The method name '{}' is not unique",
                name
            );
        }
    );
}

}// namespace GPlatform
