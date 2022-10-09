#include "GpRpcMethodsManager.hpp"

namespace GPlatform::RPC {

void    GpRpcMethodsManager::Init (void)
{
    OnInit();
}

void    GpRpcMethodsManager::Register (GpRpcMethodFactory::SP aFactory)
{
    const auto& factory = aFactory.V();
    iFactories.Register(factory.MethodName(), aFactory);
}

void    GpRpcMethodsManager::Register (GpRpcMethodsRegister& aApiMethodsRegister)
{
    aApiMethodsRegister.OnInit(*this);
}

}//namespace GPlatform::RPC
