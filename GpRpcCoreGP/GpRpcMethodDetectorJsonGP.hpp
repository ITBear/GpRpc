#pragma once

#include "GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GpRpcMethodDetectorJsonGP final: public GpRpcMethodDetector
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcMethodDetectorJsonGP)
    CLASS_DD(GpRpcMethodDetectorJsonGP)

public:
                                GpRpcMethodDetectorJsonGP   (std::string_view aJsonStr) noexcept;
    virtual                     ~GpRpcMethodDetectorJsonGP  (void) noexcept override final;

    virtual std::string         DetectApiMethodName         (void) const override final;

private:
    std::string_view            iJsonStr;
};

}//namespace GPlatform::RPC
