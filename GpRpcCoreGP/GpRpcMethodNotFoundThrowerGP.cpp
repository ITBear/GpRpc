#include "GpRpcMethodNotFoundThrowerGP.hpp"
#include "GpRpcMethodNotFoundExceptionGP.hpp"

namespace GPlatform::RPC {

void    GpRpcMethodNotFoundThrowerGP::Throw (std::string_view aMethodName) const
{
    throw GpRpcMethodNotFoundExceptionGP
    (
        GpRpcMethodNotFoundExceptionCodeGP::METHOD_NOT_FOUND,
        aMethodName
    );
}

}//namespace GPlatform::RPC
