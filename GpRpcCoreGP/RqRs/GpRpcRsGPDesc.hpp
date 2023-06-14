#pragma once

#include "GpRpcRsResultGPDesc.hpp"
#include "../../GpRpcCore/RqRs/GpRpcRsIfDesc.hpp"
#include "../../../GpCore2/GpUtils/TypeTraits/GpTypeInfoUtils.hpp"

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcRsGPDesc: public GpRpcRsIfDesc
{
public:
    CLASS_DD(GpRpcRsGPDesc)
    REFLECT_DECLARE(u8"16df1627-8643-4a94-a646-b8badd8b31c7"_uuid)

public:
                    GpRpcRsGPDesc   (void) noexcept {}
    explicit        GpRpcRsGPDesc   (const GpRpcRsGPDesc& aDesc) noexcept: GpRpcRsIfDesc(aDesc) {}
    explicit        GpRpcRsGPDesc   (GpRpcRsGPDesc&& aDesc) noexcept: GpRpcRsIfDesc(std::move(aDesc)) {}
    virtual         ~GpRpcRsGPDesc  (void) noexcept override {}
};

#define GP_RPC_RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public ::GPlatform::GpRpcRsGPDesc \
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
    using ResultT   = ::GPlatform::GpRpcRsResultGPDesc::SP; \
 \
public: \
                                    NAME##_rs   (void) noexcept; \
                                    NAME##_rs   (const NAME##_rs& aRs); \
                                    NAME##_rs   (NAME##_rs&& aRs) noexcept; \
    virtual                         ~NAME##_rs  (void) noexcept; \
 \
    virtual ::GPlatform::GpReflectObject::CSP \
                                    Result      (void) const override final; \
    virtual ::GPlatform::GpReflectObject::SP \
                                    Result      (void) override final; \
    virtual void                    SetResult   (::GPlatform::GpReflectObject::SP aResult) override final; \
 \
    virtual GpAny                   Payload     (void) const override final; \
    virtual GpAny                   Payload     (void) override final; \
    virtual void                    SetPayload  (GpAny& aAny) override final; \
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
::GPlatform::GpRpcRsGPDesc(aRs), \
data(GpReflectUtils::SCopyValue(aRs.data)), \
result(GpReflectUtils::SCopyValue(aRs.result)) \
{ \
} \
 \
NAME##_rs::NAME##_rs (NAME##_rs&& aRs) noexcept: \
::GPlatform::GpRpcRsGPDesc(std::move(aRs)), \
data(std::move(aRs.data)), \
result(std::move(aRs.result)) \
{ \
} \
 \
NAME##_rs::~NAME##_rs (void) noexcept \
{ \
} \
 \
::GPlatform::GpReflectObject::CSP   NAME##_rs::Result (void) const \
{ \
    return result; \
} \
 \
::GPlatform::GpReflectObject::SP    NAME##_rs::Result (void) \
{ \
    return result; \
} \
 \
void    NAME##_rs::SetResult (::GPlatform::GpReflectObject::SP aResult) \
{ \
    result = GpReflectManager::SCastSP<ResultT>(aResult); \
} \
 \
GpAny   NAME##_rs::Payload (void) const \
{ \
    return GpAny{DataTRefC(data)}; \
} \
 \
GpAny   NAME##_rs::Payload (void) \
{ \
    return GpAny{DataTRef(data)}; \
} \
 \
void    NAME##_rs::SetPayload (GpAny& aAny) \
{ \
    const auto& typeInfoAny = aAny.TypeInfo(); \
 \
    if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRef))) \
    { \
        data = aAny.ValueNoCheck<DataTRef>(); \
    } else if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRefC))) \
    { \
        data = aAny.ValueNoCheck<DataTRefC>(); \
    } else \
    { \
        THROW_GP(u8"Unsupported payload type"_sv); \
    } \
} \
 \
void    NAME##_rs::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
    PROP(result); \
}

}//namespace GPlatform
