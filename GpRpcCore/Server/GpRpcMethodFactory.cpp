#include "GpRpcMethodFactory.hpp"

namespace GPlatform {

GpRpcMethodFactory::GpRpcMethodFactory (std::u8string_view aMethodName):
iMethodName(aMethodName)
{
}

GpRpcMethodFactory::~GpRpcMethodFactory (void) noexcept
{
}

}//namespace GPlatform
