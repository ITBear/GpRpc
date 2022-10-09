#pragma once

#include "GpRpcCoreGP_global.hpp"

namespace GPlatform::RPC {

class GP_RPC_CORE_GP_API GpRpcClientGP: public GpRpcClient
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcClientGP)
    CLASS_DD(GpRpcClientGP)

    using TransportSerializeRqFnRes = GpRpcCliTransport::SerializeRqFnRes;
    using TransportSerializeRqFnT   = GpRpcCliTransport::SerializeRqFnT;
    using TransportProcessRqRsFnT   = GpRpcCliTransport::ProcessRqRsFnT;

protected:
    inline                          GpRpcClientGP   (GpRpcCliTransport::SP aTransport) noexcept;

public:
    virtual                         ~GpRpcClientGP  (void) noexcept {}

    template<typename RQ, typename RS>
    typename RS::DataT              ProcessRQ       (const typename RQ::DataT&              aRqData,
                                                     std::string_view                       aMethodName,
                                                     std::optional<TransportSerializeRqFnT> aBeforeTransportSerializeRqFn   = std::nullopt,
                                                     std::optional<TransportSerializeRqFnT> aAfterTransportSerializeRqFn    = std::nullopt,
                                                     std::optional<TransportProcessRqRsFnT> aBeforeTransportProcessFn       = std::nullopt,
                                                     std::optional<TransportProcessRqRsFnT> aAfterTransportProcessFn        = std::nullopt);

protected:
    virtual void                    CheckRsResult   (const GpRpcRsIfDesc&   aRsDesc,
                                                     std::string_view       aMethodName);
    virtual void                    OnBeforeRQ      (GpRpcRqIfDesc& aRq);
};

GpRpcClientGP::GpRpcClientGP (GpRpcCliTransport::SP aTransport) noexcept:
GpRpcClient(std::move(aTransport))
{
}

template<typename RQ, typename RS>
typename RS::DataT  GpRpcClientGP::ProcessRQ
(
    const typename RQ::DataT&               aRqData,
    std::string_view                        aMethodName,
    std::optional<TransportSerializeRqFnT>  aBeforeTransportSerializeRqFn,
    std::optional<TransportSerializeRqFnT>  aAfterTransportSerializeRqFn,
    std::optional<TransportProcessRqRsFnT>  aBeforeTransportProcessFn,
    std::optional<TransportProcessRqRsFnT>  aAfterTransportProcessFn
)
{
    RQ rq;
    rq.SetMethod(aMethodName);
    rq.SetPayload(std::make_any<typename RQ::DataTRefC>(aRqData));

    OnBeforeRQ(rq);

    //Do
    GpReflectObject::SP rsBase = _Transport().ProcessRQ
    (
        rq,
        {&RS::SReflectModel(), &GpRpcRsIfDesc::SReflectModel()},
        aBeforeTransportSerializeRqFn,
        aAfterTransportSerializeRqFn,
        aBeforeTransportProcessFn,
        aAfterTransportProcessFn
    );

    GpRpcRsIfDesc& rsRpc = GpReflectManager::SCastRef<GpRpcRsIfDesc>(rsBase.V());

    //Check result
    CheckRsResult(rsRpc, aMethodName);

    //Cast type
    RS& rs = GpReflectManager::SCastRef<RS>(rsRpc);

    return std::any_cast<typename RS::DataTRef>(rs.Payload());
}

}//namespace GPlatform::RPC
