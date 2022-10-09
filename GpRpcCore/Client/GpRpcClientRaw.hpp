#pragma once

#include "GpRpcClient.hpp"

namespace GPlatform::RPC {
/*
class GpRpcClientRaw: public GpRpcClient
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcClientRaw)
    CLASS_DD(GpRpcClientRaw)

    using TransportSerializeRqFnRes = GpRpcCliTransport::SerializeRqFnRes;
    using TransportSerializeRqFnT   = GpRpcCliTransport::SerializeRqFnT;
    using TransportProcessRqRsFnT   = GpRpcCliTransport::ProcessRqRsFnT;

protected:
    inline                          GpRpcClientRaw  (GpRpcCliTransport::SP aTransport) noexcept;

public:
    virtual                         ~GpRpcClientRaw (void) noexcept {}

    template<typename RQ, typename RS, typename ErrorT>
    typename RS::SP                 ProcessRQ       (RQ&                                    aRq,
                                                     std::optional<TransportSerializeRqFnT> aBeforeTransportSerializeRqFn   = std::nullopt,
                                                     std::optional<TransportSerializeRqFnT> aAfterTransportSerializeRqFn    = std::nullopt,
                                                     std::optional<TransportProcessRqRsFnT> aBeforeTransportProcessFn       = std::nullopt,
                                                     std::optional<TransportProcessRqRsFnT> aAfterTransportProcessFn        = std::nullopt);

protected:
    virtual void                    CheckRsResult   (const GpReflectObject& aRs) = 0;
    virtual void                    OnBeforeRQ      (GpReflectObject& aRq) = 0;
};

GpRpcClientRaw::GpRpcClientRaw (GpRpcCliTransport::SP aTransport) noexcept:
GpRpcClient(std::move(aTransport))
{
}

template<typename RQ, typename RS, typename ErrorT>
typename RS::SP GpRpcClientRaw::ProcessRQ
(
    RQ&                                     aRq,
    std::optional<TransportSerializeRqFnT>  aBeforeTransportSerializeRqFn,
    std::optional<TransportSerializeRqFnT>  aAfterTransportSerializeRqFn,
    std::optional<TransportProcessRqRsFnT>  aBeforeTransportProcessFn,
    std::optional<TransportProcessRqRsFnT>  aAfterTransportProcessFn
)
{
    OnBeforeRQ(aRq);

    //Do
    GpReflectObject::SP rsBase = _Transport().ProcessRQ
    (
        aRq,
        {&RS::SReflectModel(), &ErrorT::SReflectModel()},
        aBeforeTransportSerializeRqFn,
        aAfterTransportSerializeRqFn,
        aBeforeTransportProcessFn,
        aAfterTransportProcessFn
    );

    //Check result
    CheckRsResult(rsBase.V());

    //Cast type
    return GpReflectManager::SCastSP<typename RS::SP>(rsBase);
}*/

}//namespace GPlatform::RPC
