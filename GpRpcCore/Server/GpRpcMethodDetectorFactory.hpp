#pragma once

#include "GpRpcMethodDetector.hpp"

#include <GpCore2/GpUtils/Types/Containers/GpBytesArray.hpp>

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

    virtual GpRpcMethodDetector::SP NewInstance                 (GpSpanCharRW aData) const = 0;
};

}// namespace GPlatform
