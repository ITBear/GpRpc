#include <GpRpc/GpRpcHttp/GpRpcHttpLib.hpp>
#include <GpCore2/GpUtils/Other/GpLinkedLibsInfo.hpp>

GP_STATIC_INITIALIZER_IMPL(GpRpcHttp)
GP_LIB_REGISTRATOR(GpRpcHttpLib)

void    GpRpcHttp_StaticInitializer::OnInitialize (void)
{
    GpRpcHttpLib::SRegisterSelf();
}
