#include <GpRpc/GpRpcCore/Server/GpRpcMethodFactory.hpp>

namespace GPlatform {

GpRpcMethodFactory::GpRpcMethodFactory (std::string_view aMethodName):
iMethodName(aMethodName)
{
}

GpRpcMethodFactory::~GpRpcMethodFactory (void) noexcept
{
}

}// namespace GPlatform
