#pragma once

#include "../GpRpcCoreJson_global.hpp"
#include "../../GpCore2/GpReflection/GpReflectUtils.hpp"
#include "../../GpRpcCore/RqRs/GpRpcRqIfDesc.hpp"
#include "../../../GpCore2/GpUtils/TypeTraits/GpTypeInfoUtils.hpp"

namespace GPlatform {

class GP_RPC_CORE_JSON_API GpRpcRqJsonDesc: public GpRpcRqIfDesc
{
public:
    CLASS_DD(GpRpcRqJsonDesc)
    REFLECT_DECLARE(u8"b127a692-821c-4019-91c8-416ee7e2963a"_uuid)

public:
    inline                      GpRpcRqJsonDesc     (void) noexcept;
    inline explicit             GpRpcRqJsonDesc     (const GpRpcRqJsonDesc& aDesc);
    inline explicit             GpRpcRqJsonDesc     (GpRpcRqJsonDesc&& aDesc) noexcept;
    virtual                     ~GpRpcRqJsonDesc    (void) noexcept override;

    virtual std::u8string_view  Method              (void) const override final;
    virtual void                SetMethod           (std::u8string_view aMethod) override final;

public:
    std::u8string               jsonrpc = u8"2.0";
    s_int_64                    id      = 1;
    std::u8string               method;
};

GpRpcRqJsonDesc::GpRpcRqJsonDesc (void) noexcept
{
}

GpRpcRqJsonDesc::GpRpcRqJsonDesc (const GpRpcRqJsonDesc& aDesc):
GpRpcRqIfDesc(aDesc),
jsonrpc(GpReflectUtils::SCopyValue(aDesc.jsonrpc)),
id     (GpReflectUtils::SCopyValue(aDesc.id)),
method (GpReflectUtils::SCopyValue(aDesc.method))
{
}

GpRpcRqJsonDesc::GpRpcRqJsonDesc (GpRpcRqJsonDesc&& aDesc) noexcept:
GpRpcRqIfDesc(std::move(aDesc)),
jsonrpc(std::move(aDesc.jsonrpc)),
id     (std::move(aDesc.id)),
method (std::move(aDesc.method))
{
}

#define JSON_RPC_API_RQ(PREFIX, NAME, UUID) \
class PREFIX NAME##_rq final: public GpRpcRqJsonDesc \
{ \
public: \
    CLASS_DD(NAME##_rq) \
    REFLECT_DECLARE(UUID) \
 \
public: \
 \
    using DataT     = NAME##_rq_data; \
    using DataTRef  = std::reference_wrapper<DataT>; \
    using DataTRefC = std::reference_wrapper<const DataT>; \
 \
public: \
                        NAME##_rq   (void) noexcept; \
                        NAME##_rq   (const NAME##_rq& aRq); \
                        NAME##_rq   (NAME##_rq&& aRq) noexcept; \
                        NAME##_rq   (DataT&& aData) noexcept; \
    virtual             ~NAME##_rq  (void) noexcept; \
 \
    virtual GpAny       Payload     (void) const override final; \
    virtual GpAny       Payload     (void) override final; \
    virtual void        SetPayload  (GpAny& aAny) override final; \
 \
public: \
    DataT               params; \
};

#define JSON_RPC_API_RQ_IMPL(NAME) \
REFLECT_IMPLEMENT(NAME##_rq, GP_MODULE_UUID) \
 \
NAME##_rq::NAME##_rq (void) noexcept \
{ \
} \
 \
NAME##_rq::NAME##_rq (const NAME##_rq& aRq): \
GpRpcRqJsonDesc(aRq), \
params(GpReflectUtils::SCopyValue(aRq.params)) \
{ \
} \
 \
NAME##_rq::NAME##_rq (NAME##_rq&& aRq) noexcept: \
GpRpcRqJsonDesc(std::move(aRq)), \
params(std::move(aRq.params)) \
{ \
} \
 \
NAME##_rq::NAME##_rq (DataT&& aData) noexcept: \
params(std::move(aData)) \
{ \
} \
 \
NAME##_rq::~NAME##_rq (void) noexcept \
{ \
} \
 \
GpAny   NAME##_rq::Payload (void) const \
{ \
   return GpAny{DataTRefC(params)}; \
} \
 \
GpAny   NAME##_rq::Payload (void) \
{ \
   return GpAny{DataTRef(params)}; \
} \
 \
void    NAME##_rq::SetPayload (GpAny& aAny) \
{ \
   const auto& typeInfoAny = aAny.TypeInfo(); \
\
   if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRef))) \
   { \
       params = aAny.ValueNoCheck<DataTRef>(); \
   } else if (GpTypeInfoUtils::SIsSame(typeInfoAny, typeid(DataTRefC))) \
   { \
       params = aAny.ValueNoCheck<DataTRefC>(); \
   } else \
   { \
       THROW_GP(u8"Unsupported payload type"_sv); \
   } \
} \
 \
void    NAME##_rq::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut) \
{ \
    PROP_F(params, (GpReflectPropFlags{GpReflectPropFlags::value_type{GpReflectPropFlag::AS_TUPLE, ""_sv}})); \
}

}//namespace GPlatform
