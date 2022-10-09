#pragma once

#include "RqRs/GpRpcRqRsGP.hpp"

namespace GPlatform::RPC {

#define GP_RPC_METHOD(NAME) \
 \
class NAME final: public ::GPlatform::RPC::GpRpcMethod \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME) \
    CLASS_DD(NAME) \
 \
    using RqT   = NAME##_rq; \
    using RsT   = NAME##_rs; \
 \
    static ::GPlatform::RPC::GpRpcMethodFactory::SP SFactory    (void); \
 \
public: \
                                            NAME            (void) noexcept; \
    virtual                                 ~NAME           (void) noexcept override final; \
 \
    virtual ::GPlatform::RPC::GpRpcRsIfDesc::SP \
                                            Process         (::GPlatform::RPC::GpRpcRqIfDesc& aRq) override final; \
    virtual const GpReflectModel&           RqReflectModel  (void) const noexcept override final; \
    virtual const GpReflectModel&           RsReflectModel  (void) const noexcept override final; \
    virtual std::string_view                MethodName      (void) const noexcept override final; \
 \
protected: \
    typename RsT::DataT                     _Process            (RqT& aRq); \
};

#define GP_RPC_METHOD_IMPL(NAME) \
 \
class NAME##_Factory final: public ::GPlatform::RPC::GpRpcMethodFactory \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME##_Factory) \
    CLASS_DD(NAME##_Factory) \
 \
public: \
                                NAME##_Factory  (void) noexcept: ::GPlatform::RPC::GpRpcMethodFactory(#NAME) {} \
    virtual                     ~NAME##_Factory (void) noexcept override final {} \
 \
    virtual GpSP<::GPlatform::RPC::GpRpcMethod> \
                                NewInstance     (void) const override final {return MakeSP<NAME>();} \
 \
}; \
 \
::GPlatform::RPC::GpRpcMethodFactory::SP    NAME::SFactory (void) \
{ \
    return MakeSP<NAME##_Factory>(); \
} \
 \
NAME::NAME (void) noexcept \
{ \
} \
 \
NAME::~NAME (void) noexcept \
{ \
} \
 \
::GPlatform::RPC::GpRpcRsIfDesc::SP NAME::Process (::GPlatform::RPC::GpRpcRqIfDesc& aRq) \
{ \
    RsT::SP     rs      = MakeSP<RsT>(); \
    RsT::DataT  rsData  = _Process(static_cast<RqT&>(aRq)); \
    rs.Vn().SetPayload(std::make_any<typename RsT::DataTRef>(rsData)); \
 \
    return rs; \
} \
 \
const GpReflectModel&   NAME::RqReflectModel (void) const noexcept \
{ \
    return RqT::SReflectModel(); \
} \
 \
const GpReflectModel&   NAME::RsReflectModel (void) const noexcept \
{ \
    return RsT::SReflectModel(); \
} \
 \
std::string_view    NAME::MethodName (void) const noexcept \
{ \
    return std::string_view(#NAME); \
}

}//namespace GPlatform::RPC
