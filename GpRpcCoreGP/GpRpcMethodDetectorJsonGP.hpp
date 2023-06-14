#pragma once

#include "GpRpcCoreGP_global.hpp"
#include "../GpRpcCore/Server/GpRpcMethodDetector.hpp"

namespace GPlatform {

class GpRpcMethodDetectorJsonGP final: public GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodDetectorJsonGP)
    CLASS_DD(GpRpcMethodDetectorJsonGP)

public:
    inline              GpRpcMethodDetectorJsonGP   (GpSpanPtrCharRW aJsonStr) noexcept;
    virtual             ~GpRpcMethodDetectorJsonGP  (void) noexcept override final;

    virtual ResT        DetectApiMethodName         (void) const override final;

private:
    GpSpanPtrCharRW     iJsonStr;
};

GpRpcMethodDetectorJsonGP::GpRpcMethodDetectorJsonGP (GpSpanPtrCharRW aJsonStr) noexcept:
iJsonStr(std::move(aJsonStr))
{
}

}//namespace GPlatform
