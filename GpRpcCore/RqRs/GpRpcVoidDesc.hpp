#pragma once

#include "../GpRpcCore_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_API GpRpcVoidDesc: public GpReflectObject
{
public:
    CLASS_DD(GpRpcVoidDesc)
    REFLECT_DECLARE("f38857d3-6c29-414b-9761-4128391a2a33"_uuid)

public:
                        GpRpcVoidDesc   (void) noexcept {}
    explicit            GpRpcVoidDesc   (const GpRpcVoidDesc& aDesc) noexcept: GpReflectObject(aDesc){};
    explicit            GpRpcVoidDesc   (GpRpcVoidDesc&& aDesc) noexcept: GpReflectObject(std::move(aDesc)){};
    virtual             ~GpRpcVoidDesc  (void) noexcept override {}
};

}//namespace GPlatform::RPC
