#pragma once

#include "GpRpcRsResultJsonDesc.hpp"
#include "../../GpRpcCore/RqRs/GpRpcRsIfDesc.hpp"
#include "../../../GpCore2/GpUtils/TypeTraits/GpTypeInfoUtils.hpp"

namespace GPlatform {

class GP_RPC_CORE_JSON_API GpRpcRsJsonDesc: public GpRpcRsIfDesc
{
public:
    CLASS_DD(GpRpcRsJsonDesc)
    REFLECT_DECLARE(u8"2b335342-83fd-48f5-8427-6787f794d156"_uuid)

public:
    inline                          GpRpcRsJsonDesc     (void) noexcept;
    inline explicit                 GpRpcRsJsonDesc     (const GpRpcRsJsonDesc& aDesc);
    inline explicit                 GpRpcRsJsonDesc     (GpRpcRsJsonDesc&& aDesc) noexcept;
    virtual                         ~GpRpcRsJsonDesc    (void) noexcept override;

    virtual GpReflectObject::CSP    Result              (void) const override final;
    virtual GpReflectObject::SP     Result              (void) override final;
    virtual void                    SetResult           (GpReflectObject::SP aResult) override final;

public:
    std::u8string                   jsonrpc = u8"2.0";
    s_int_64                        id      = 1;
    GpRpcRsResultJsonDesc::SP       error;
};

GpRpcRsJsonDesc::GpRpcRsJsonDesc (void) noexcept
{
}

GpRpcRsJsonDesc::GpRpcRsJsonDesc (const GpRpcRsJsonDesc& aDesc):
GpRpcRsIfDesc(aDesc),
jsonrpc(GpReflectUtils::SCopyValue(aDesc.jsonrpc)),
id     (GpReflectUtils::SCopyValue(aDesc.id)),
error  (GpReflectUtils::SCopyValue(aDesc.error))
{
}

GpRpcRsJsonDesc::GpRpcRsJsonDesc (GpRpcRsJsonDesc&& aDesc) noexcept:
GpRpcRsIfDesc(std::move(aDesc)),
jsonrpc(std::move(aDesc.jsonrpc)),
id(std::move(aDesc.id)),
error(std::move(aDesc.error))
{
}

#define JSON_RPC_API_RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public GpRpcRsJsonDesc \
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
 \
public: \
                        NAME##_rs   (void) noexcept; \
                        NAME##_rs   (const NAME##_rs& aRs); \
                        NAME##_rs   (NAME##_rs&& aRs) noexcept; \
    virtual             ~NAME##_rs  (void) noexcept; \
 \
    virtual GpAny       Payload     (void) const override final; \
    virtual sGpAny      Payload     (void) override final; \
    virtual void        SetPayload  (GpAny& aAny) override final; \
 \
public: \
    DataT               result; \
};

#define JSON_RPC_API_RS_IMPL(NAME) \
REFLECT_IMPLEMENT(NAME##_rs, GP_MODULE_UUID) \
 \
NAME##_rs::NAME##_rs (void) noexcept \
{ \
} \
 \
NAME##_rs::NAME##_rs (const NAME##_rs& aRs) noexcept: \
GpRpcRsJsonDesc(aRs), \
result(GpReflectUtils::SCopyValue(aRs.result)) \
{ \
} \
 \
NAME##_rs::NAME##_rs (NAME##_rs&& aRs) noexcept: \
GpRpcRsJsonDesc(std::move(aRs)), \
result(std::move(aRs.result)) \
{ \
} \
 \
NAME##_rs::~NAME##_rs (void) noexcept \
{ \
} \
 \
GpAny   NAME##_rs::Payload (void) const \
{ \
    return GpAny{DataTRefC(result)}; \
} \
 \
GpAny   NAME##_rs::Payload (void) \
{ \
    return GpAny{DataTRef(result)}; \
} \
 \
void    NAME##_rs::SetPayload (GpAny& aAny) \
{ \
    const auto& typeInfoAny = aAny.TypeInfo(); \
 \
    if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRef))) \
    { \
        result = aAny.ValueNoCheck<DataTRef>(aAny); \
    } else if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRefC))) \
    { \
        result = aAny.ValueNoCheck<DataTRefC>(aAny); \
    } else \
    { \
        THROW_GP(u8"Unsupported payload type"_sv); \
    } \
} \
 \
void    NAME##_rs::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut) \
{ \
    PROP(result); \
}

}//namespace GPlatform
