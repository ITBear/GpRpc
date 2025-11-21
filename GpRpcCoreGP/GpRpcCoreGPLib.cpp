#include <GpRpc/GpRpcCoreGP/GpRpcCoreGPLib.hpp>
#include <GpCore2/GpUtils/Other/GpLinkedLibsInfo.hpp>

GP_STATIC_INITIALIZER_IMPL(GpRpcCoreGP)
GP_LIB_REGISTRATOR(GpRpcCoreGPLib)

void    GpRpcCoreGP_StaticInitializer::OnInitialize (void)
{
    GpRpcCoreGPLib::SRegisterSelf();
}
