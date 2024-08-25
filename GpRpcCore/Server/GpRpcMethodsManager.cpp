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
    const bool          isInserted  = std::get<1>(iFactories.TrySet(factory.MethodName(), aFactory));

    THROW_COND_GP
    (
        isInserted == true,
        [name]()
        {
            return fmt::format
            (
                "Method name {} is not unique",
                name
            );
        }
    );
}

}// namespace GPlatform
