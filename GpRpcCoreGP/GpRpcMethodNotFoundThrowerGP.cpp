#include "GpRpcMethodNotFoundThrowerGP.hpp"
#include "GpRpcMethodNotFoundExceptionGP.hpp"

namespace GPlatform {

void    GpRpcMethodNotFoundThrowerGP::Throw (std::u8string_view aMethodName) const
{
    THROW_METHOD_NOT_FOUND_GP
    (
        GpRpcMethodNotFoundExceptionCodeGP::METHOD_NOT_FOUND,
        aMethodName
    );
}

}//namespace GPlatform
