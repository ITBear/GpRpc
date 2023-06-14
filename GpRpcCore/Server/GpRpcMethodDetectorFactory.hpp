#pragma once

#include "GpRpcMethodDetector.hpp"

namespace GPlatform {

class GpRpcMethodDetectorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetectorFactory)
    CLASS_DD(GpRpcMethodDetectorFactory)

protected:
                                    GpRpcMethodDetectorFactory  (void) noexcept {}

public:
    virtual                         ~GpRpcMethodDetectorFactory (void) noexcept {}

    virtual GpRpcMethodDetector::SP NewInstance                 (GpSpanPtrCharRW aData) const = 0;
};

}//namespace GPlatform
