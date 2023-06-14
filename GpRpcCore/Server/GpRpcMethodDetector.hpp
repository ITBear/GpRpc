#pragma once

#include "GpRpcMethod.hpp"
#include "../../../GpCore2/GpReflection/Serializers/GpReflectSerializerCtx.hpp"

namespace GPlatform {

class GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetector)
    CLASS_DD(GpRpcMethodDetector)

    using ResT = std::tuple<std::optional<std::u8string>, GpReflectSerializerCtx::SP>;

public:
                        GpRpcMethodDetector     (void) noexcept {}
    virtual             ~GpRpcMethodDetector    (void) noexcept {}

    virtual ResT        DetectApiMethodName     (void) const = 0;
};

}//namespace GPlatform
