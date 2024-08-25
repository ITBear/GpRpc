#pragma once

#include <GpCore2/GpUtils/Types/Containers/GpBytesArray.hpp>
#include <GpRpc/GpRpcCore/Server/GpRpcMethodDetector.hpp>

namespace GPlatform {

class GpRpcMethodDetectorJsonGP final: public GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodDetectorJsonGP)
    CLASS_DD(GpRpcMethodDetectorJsonGP)

public:
    inline              GpRpcMethodDetectorJsonGP   (GpSpanCharRW aJsonStr) noexcept;
    virtual             ~GpRpcMethodDetectorJsonGP  (void) noexcept override final;

    virtual ResT        DetectApiMethodName         (void) const override final;

private:
    GpSpanCharRW        iJsonStr;
};

GpRpcMethodDetectorJsonGP::GpRpcMethodDetectorJsonGP (GpSpanCharRW aJsonStr) noexcept:
iJsonStr{std::move(aJsonStr)}
{
}

}// namespace GPlatform
