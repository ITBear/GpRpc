#pragma once

namespace GPlatform {

#define GP_RPC_METHOD(NAME) \
 \
class NAME final: public ::GPlatform::GpRpcMethod \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME) \
    CLASS_DD(NAME) \
 \
    using RqT   = NAME##_rq; \
    using RsT   = NAME##_rs; \
 \
    static ::GPlatform::GpRpcMethodFactory::SP  SFactory    (void); \
 \
public: \
                                            NAME            (void) noexcept; \
    virtual                                 ~NAME           (void) noexcept override final; \
 \
    virtual ::GPlatform::GpRpcRsIfDesc::SP \
                                            Process         (::GPlatform::GpRpcRqIfDesc& aRq) override final; \
    virtual GpReflectModel::CSP             RqReflectModel  (void) const noexcept override final; \
    virtual GpReflectModel::CSP             RsReflectModel  (void) const noexcept override final; \
    virtual std::string_view                MethodName      (void) const noexcept override final; \
 \
protected: \
    typename RsT::DataT                     _Process            (RqT& aRq); \
};

#define GP_RPC_METHOD_IMPL(NAME) \
 \
class NAME##_Factory final: public ::GPlatform::GpRpcMethodFactory \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME##_Factory) \
    CLASS_DD(NAME##_Factory) \
 \
public: \
                                NAME##_Factory  (void) noexcept: ::GPlatform::GpRpcMethodFactory(#NAME) {} \
    virtual                     ~NAME##_Factory (void) noexcept override final {} \
 \
    virtual GpSP<::GPlatform::GpRpcMethod> \
                                NewInstance     (void) const override final {return MakeSP<NAME>();} \
 \
}; \
 \
::GPlatform::GpRpcMethodFactory::SP NAME::SFactory (void) \
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
::GPlatform::GpRpcRsIfDesc::SP  NAME::Process (::GPlatform::GpRpcRqIfDesc& aRq) \
{ \
    RsT::SP     rs          = MakeSP<RsT>(); \
    RsT::DataT  rsData      = _Process(static_cast<RqT&>(aRq)); \
    auto        rsDataAny   = GpAny{typename RsT::DataTRef(rsData)}; \
    rs.Vn().SetPayload(rsDataAny); \
 \
    return rs; \
} \
 \
GpReflectModel::CSP NAME::RqReflectModel (void) const noexcept \
{ \
    return RqT::SReflectModel(); \
} \
 \
GpReflectModel::CSP NAME::RsReflectModel (void) const noexcept \
{ \
    return RsT::SReflectModel(); \
} \
 \
std::string_view    NAME::MethodName (void) const noexcept \
{ \
    return {#NAME}; \
}

}// namespace GPlatform
