#pragma once

#include <GpRpc/GpRpcCoreGP/GpRpcCoreGP_global.hpp>
#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>
#include <GpRpc/GpRpcCore/Server/GpRpcMethodDetectorFactory.hpp>

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcMethodDetectorJsonFactoryGP final: public GpRpcMethodDetectorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcMethodDetectorJsonFactoryGP)
    CLASS_DD(GpRpcMethodDetectorJsonFactoryGP)

public:
                                    GpRpcMethodDetectorJsonFactoryGP    (void) noexcept;
    virtual                         ~GpRpcMethodDetectorJsonFactoryGP   (void) noexcept override final;

    virtual GpRpcMethodDetector::SP NewInstance                         (GpSpanCharRW aData) const override final;
};

}// namespace GPlatform
