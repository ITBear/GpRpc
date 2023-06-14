#include "GpRpcMethodsManager.hpp"

namespace GPlatform {

void    GpRpcMethodsManager::Init (void)
{
    OnInit();
}

void    GpRpcMethodsManager::Register (GpRpcMethodFactory::SP aFactory)
{
    const auto& factory = aFactory.V();
    iFactories.Set(factory.MethodName(), aFactory);
}

void    GpRpcMethodsManager::Register (GpRpcMethodsRegister& aApiMethodsRegister)
{
    aApiMethodsRegister.OnInit(*this);
}

}//namespace GPlatform
