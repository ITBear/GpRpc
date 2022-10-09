#include "GpRpcMethodFactory.hpp"

namespace GPlatform::RPC {

GpRpcMethodFactory::GpRpcMethodFactory (std::string_view aMethodName):
iMethodName(aMethodName)
{
}

GpRpcMethodFactory::~GpRpcMethodFactory (void) noexcept
{
}

}//namespace GPlatform::RPC
