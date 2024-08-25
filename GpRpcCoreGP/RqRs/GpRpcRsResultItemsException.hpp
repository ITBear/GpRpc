#pragma once

#include <GpRpc/GpRpcCoreGP/RqRs/GpRpcRsResultGPDesc.hpp>

namespace GPlatform {

GP_ENUM(GP_RPC_CORE_GP_API, GpRpcRsResultItemsExceptionCode,
    MULTIPLE_ERRORS
);

class GP_RPC_CORE_GP_API GpRpcRsResultItemsException final: public GpException
{
public:
    using ItemT = GpRpcRsResultGPDesc::ItemT;

public:
                        GpRpcRsResultItemsException     (void) noexcept = delete;
    inline explicit     GpRpcRsResultItemsException     (const GpRpcRsResultItemsException& aException);
    inline explicit     GpRpcRsResultItemsException     (GpRpcRsResultItemsException&& aException);
    inline explicit     GpRpcRsResultItemsException     (ItemT::C::Vec::SP&&    aItems,
                                                         const SourceLocationT& aSourceLocation = SourceLocationT::current());
    virtual             ~GpRpcRsResultItemsException    (void) noexcept override final;

public:
    ItemT::C::Vec::SP   iItems;
};

GpRpcRsResultItemsException::GpRpcRsResultItemsException (const GpRpcRsResultItemsException& aException):
GpException{aException},
iItems{GpReflectUtils::SCopyValue(aException.iItems)}
{
}

GpRpcRsResultItemsException::GpRpcRsResultItemsException (GpRpcRsResultItemsException&& aException):
GpException{std::move(aException)},
iItems{std::move(aException.iItems)}
{
}

GpRpcRsResultItemsException::GpRpcRsResultItemsException
(
    ItemT::C::Vec::SP&&     aItems,
    const SourceLocationT&  aSourceLocation
):
GpException{"Multiple errors", aSourceLocation},
iItems{std::move(aItems)}
{
}

}// namespace GPlatform
