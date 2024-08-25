#pragma once

#include <GpRpc/GpRpcCoreGP/GpRpcMethodNotFoundExceptionCodeGP.hpp>
#include <GpCore2/GpUtils/Exceptions/GpExceptionCode.hpp>

namespace GPlatform {

using GpRpcMethodNotFoundExceptionGPCode = GpRpcMethodNotFoundExceptionCodeGP;

EXCEPTION_CODE(, GpRpcMethodNotFoundExceptionGP, METHOD_NOT_FOUND_GP)

}// namespace GPlatform
