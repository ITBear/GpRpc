#pragma once

#include "../GpRpcCoreJson_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_JSON_API GpRpcRsResultJsonDesc final: public GpRpcRsResultIfDesc
{
public:
    CLASS_DD(GpRpcRsResultJsonDesc)
    REFLECT_DECLARE("4297c2ba-8831-47c0-9247-ed50d4dcb3a7"_uuid)

public:
                        GpRpcRsResultJsonDesc   (void) noexcept;
                        GpRpcRsResultJsonDesc   (const GpRpcRsResultJsonDesc& aDesc);
                        GpRpcRsResultJsonDesc   (GpRpcRsResultJsonDesc&& aDesc) noexcept;
    virtual             ~GpRpcRsResultJsonDesc  (void) noexcept override final;

public:
    s_int_64            code    = 0;
    std::string         message;
};

}//namespace GPlatform::RPC
