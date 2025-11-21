#include <GpRpc/GpRpcCore/GpRpcCoreLib.hpp>
#include <GpCore2/GpUtils/Other/GpLinkedLibsInfo.hpp>

GP_STATIC_INITIALIZER_IMPL(GpRpcCore)
GP_LIB_REGISTRATOR(GpRpcCoreLib)

void    GpRpcCore_StaticInitializer::OnInitialize (void)
{
    GpRpcCoreLib::SRegisterSelf();
}
