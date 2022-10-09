#pragma once

#include "GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcMethodDetectorJsonFactoryGP final: public GpRpcMethodDetectorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetectorJsonFactoryGP)
    CLASS_DD(GpRpcMethodDetectorJsonFactoryGP)

public:
                                    GpRpcMethodDetectorJsonFactoryGP    (void) noexcept;
    virtual                         ~GpRpcMethodDetectorJsonFactoryGP   (void) noexcept override final;

    virtual GpRpcMethodDetector::SP NewInstance                         (GpSpanPtrByteR aData) const override final;
};

}//namespace GPlatform::RPC
