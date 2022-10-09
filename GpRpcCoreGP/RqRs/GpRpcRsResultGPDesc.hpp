#pragma once

#include "../GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcRsResultGPDesc final: public GpRpcRsResultIfDesc
{
public:
    CLASS_DD(GpRpcRsResultGPDesc)
    REFLECT_DECLARE("ae323226-0b92-4010-8582-317185e8885f"_uuid)

public:
                        GpRpcRsResultGPDesc     (void) noexcept {}
                        GpRpcRsResultGPDesc     (const GpRpcRsResultGPDesc& aDesc);
                        GpRpcRsResultGPDesc     (GpRpcRsResultGPDesc&& aDesc) noexcept;
                        GpRpcRsResultGPDesc     (std::string    aCode,
                                                 std::string    aMsg) noexcept;
    virtual             ~GpRpcRsResultGPDesc    (void) noexcept override;

public:
    std::string         code    = "OK";
    std::string         msg;
};

}//namespace GPlatform::RPC
