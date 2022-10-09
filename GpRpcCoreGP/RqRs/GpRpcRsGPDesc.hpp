#pragma once

#include "GpRpcRsResultGPDesc.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcRsGPDesc: public GpRpcRsIfDesc
{
public:
    CLASS_DD(GpRpcRsGPDesc)
    REFLECT_DECLARE("16df1627-8643-4a94-a646-b8badd8b31c7"_uuid)

public:
                    GpRpcRsGPDesc   (void) noexcept {}
    explicit        GpRpcRsGPDesc   (const GpRpcRsGPDesc& aDesc) noexcept: GpRpcRsIfDesc(aDesc) {}
    explicit        GpRpcRsGPDesc   (GpRpcRsGPDesc&& aDesc) noexcept: GpRpcRsIfDesc(std::move(aDesc)) {}
    virtual         ~GpRpcRsGPDesc  (void) noexcept override {}
};

#define GP_RPC_RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public ::GPlatform::RPC::GpRpcRsGPDesc \
{ \
public: \
    CLASS_DD(NAME##_rs) \
    REFLECT_DECLARE(UUID) \
 \
public: \
 \
    using DataT     = NAME##_rs_data; \
    using DataTRef  = std::reference_wrapper<DataT>; \
    using DataTRefC = std::reference_wrapper<const DataT>; \
    using ResultT   = ::GPlatform::RPC::GpRpcRsResultGPDesc::SP; \
 \
public: \
                                    NAME##_rs   (void) noexcept; \
                                    NAME##_rs   (const NAME##_rs& aRs); \
                                    NAME##_rs   (NAME##_rs&& aRs) noexcept; \
    virtual                         ~NAME##_rs  (void) noexcept; \
 \
    virtual ::GPlatform::RPC::GpRpcRsResultIfDesc::CSP \
                                    Result      (void) const override final; \
    virtual ::GPlatform::RPC::GpRpcRsResultIfDesc::SP \
                                    Result      (void) override final; \
    virtual void                    SetResult   (::GPlatform::RPC::GpRpcRsResultIfDesc::SP aResult) override final; \
 \
    virtual std::any                Payload     (void) const override final; \
    virtual std::any                Payload     (void) override final; \
    virtual void                    SetPayload  (std::any aAny) override final; \
 \
public: \
    DataT               data; \
    ResultT             result; \
};

#define GP_RPC_RS_IMPL(NAME) \
REFLECT_IMPLEMENT(NAME##_rs, GP_MODULE_UUID) \
 \
NAME##_rs::NAME##_rs (void) noexcept \
{ \
} \
 \
NAME##_rs::NAME##_rs (const NAME##_rs& aRs): \
::GPlatform::RPC::GpRpcRsGPDesc(aRs), \
data(GpReflectUtils::SCopyValue(aRs.data)), \
result(GpReflectUtils::SCopyValue(aRs.result)) \
{ \
} \
 \
NAME##_rs::NAME##_rs (NAME##_rs&& aRs) noexcept: \
::GPlatform::RPC::GpRpcRsGPDesc(std::move(aRs)), \
data(std::move(aRs.data)), \
result(std::move(aRs.result)) \
{ \
} \
 \
NAME##_rs::~NAME##_rs (void) noexcept \
{ \
} \
 \
::GPlatform::RPC::GpRpcRsResultIfDesc::CSP  NAME##_rs::Result (void) const \
{ \
    return result; \
} \
 \
::GPlatform::RPC::GpRpcRsResultIfDesc::SP   NAME##_rs::Result (void) \
{ \
    return result; \
} \
 \
void    NAME##_rs::SetResult (::GPlatform::RPC::GpRpcRsResultIfDesc::SP aResult) \
{ \
    result = GpReflectManager::SCastSP<ResultT>(aResult); \
} \
 \
std::any    NAME##_rs::Payload (void) const \
{ \
    return std::make_any<DataTRefC>(data); \
} \
 \
std::any    NAME##_rs::Payload (void) \
{ \
    return std::make_any<DataTRef>(data); \
} \
 \
void    NAME##_rs::SetPayload (std::any aAny) \
{ \
    const auto& typeInfoAny = aAny.type(); \
 \
    if (typeInfoAny == typeid(DataTRef)) \
    { \
        data = std::any_cast<DataTRef>(aAny); \
    } else if (typeInfoAny == typeid(DataTRefC)) \
    { \
        data = std::any_cast<DataTRefC>(aAny); \
    } else \
    { \
        throw std::bad_any_cast(); \
    } \
} \
 \
void    NAME##_rs::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
    PROP(result); \
}

}//namespace GPlatform::RPC
