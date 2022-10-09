#pragma once

#include "GpRpcMethod.hpp"

namespace GPlatform::RPC {

class GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetector)
    CLASS_DD(GpRpcMethodDetector)

public:
                            GpRpcMethodDetector     (void) noexcept {}
    virtual                 ~GpRpcMethodDetector    (void) noexcept {}

    virtual std::string     DetectApiMethodName     (void) const = 0;
};

}//namespace GPlatform::RPC
