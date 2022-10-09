#pragma once

#include "../GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcRqGPDesc: public GpRpcRqIfDesc
{
public:
    CLASS_DD(GpRpcRqGPDesc)
    REFLECT_DECLARE("e30c3a62-e95e-496a-abe2-370ff474aeca"_uuid)

public:
    inline                      GpRpcRqGPDesc   (void) noexcept;
    inline explicit             GpRpcRqGPDesc   (const GpRpcRqGPDesc& aDesc);
    inline explicit             GpRpcRqGPDesc   (GpRpcRqGPDesc&& aDesc) noexcept;
    virtual                     ~GpRpcRqGPDesc  (void) noexcept override;

    virtual std::string_view    Method              (void) const override final;
    virtual void                SetMethod           (std::string_view aMethod) override final;

public:
    std::string                 method;
    std::string                 sid;    //TODO: make optional
};

GpRpcRqGPDesc::GpRpcRqGPDesc (void) noexcept
{
}

GpRpcRqGPDesc::GpRpcRqGPDesc (const GpRpcRqGPDesc& aDesc):
GpRpcRqIfDesc(aDesc),
method(aDesc.method),
sid(aDesc.sid)
{
}

GpRpcRqGPDesc::GpRpcRqGPDesc (GpRpcRqGPDesc&& aDesc) noexcept:
GpRpcRqIfDesc(std::move(aDesc)),
method(std::move(aDesc.method)),
sid(std::move(aDesc.sid))
{
}

#define GP_RPC_RQ(PREFIX, NAME, UUID) \
class PREFIX NAME##_rq final: public ::GPlatform::RPC::GpRpcRqGPDesc \
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
    virtual std::any    Payload     (void) const override final; \
    virtual std::any    Payload     (void) override final; \
    virtual void        SetPayload  (std::any aAny) override final; \
 \
public: \
    DataT               data; \
};

#define GP_RPC_RQ_IMPL(NAME) \
REFLECT_IMPLEMENT(NAME##_rq, GP_MODULE_UUID) \
 \
NAME##_rq::NAME##_rq (void) noexcept \
{ \
} \
\
NAME##_rq::NAME##_rq (const NAME##_rq& aRq): \
::GPlatform::RPC::GpRpcRqGPDesc(aRq), \
data(GpReflectUtils::SCopyValue(aRq.data)) \
{ \
} \
 \
NAME##_rq::NAME##_rq (NAME##_rq&& aRq) noexcept: \
::GPlatform::RPC::GpRpcRqGPDesc(std::move(aRq)), \
data(std::move(aRq.data)) \
{ \
} \
 \
NAME##_rq::NAME##_rq (DataT&& aData) noexcept: \
data(std::move(aData)) \
{ \
} \
 \
NAME##_rq::~NAME##_rq (void) noexcept \
{ \
} \
 \
std::any    NAME##_rq::Payload (void) const \
{ \
   return std::make_any<DataTRefC>(data); \
} \
 \
std::any    NAME##_rq::Payload (void) \
{ \
   return std::make_any<DataTRef>(data); \
} \
 \
void    NAME##_rq::SetPayload (std::any aAny) \
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
void    NAME##_rq::_SReflectCollectProps (GpReflectProp::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
}

}//GPlatform::RPC
