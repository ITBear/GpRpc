#pragma once

#include <GpCore2/GpReflection/Serializers/GpReflectSerializerCtx.hpp>

namespace GPlatform {

class GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetector)
    CLASS_DD(GpRpcMethodDetector)

    using ResT = std::tuple<std::string, GpReflectSerializerCtx::SP>;

public:
                        GpRpcMethodDetector     (void) noexcept = default;
    virtual             ~GpRpcMethodDetector    (void) noexcept = default;

    virtual ResT        DetectApiMethodName     (void) const = 0;
};

}// namespace GPlatform
