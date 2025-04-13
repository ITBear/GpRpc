#include <GpRpc/GpRpcCoreGP/GpRpcMethodNotFoundThrowerGP.hpp>
#include <GpRpc/GpRpcCoreGP/GpRpcMethodNotFoundExceptionGP.hpp>

namespace GPlatform {

void    GpRpcMethodNotFoundThrowerGP::Throw (std::string_view aMethodName) const
{
    THROW
    (
        GpRpcMethodNotFoundExceptionCodeGP::METHOD_NOT_FOUND,
        aMethodName
    );
}

}// namespace GPlatform
