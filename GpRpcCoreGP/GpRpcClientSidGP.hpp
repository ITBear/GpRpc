#pragma once

#include "GpRpcClientGP.hpp"

namespace GPlatform {

class GP_RPC_CORE_GP_API GpRpcClientSidGP: public GpRpcClientGP
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcClientSidGP)
    CLASS_DD(GpRpcClientSidGP)

public:
    inline                  GpRpcClientSidGP    (GpRpcCliTransport::SP aTransport) noexcept;
    virtual                 ~GpRpcClientSidGP   (void) noexcept override;

    inline void             SetSID              (std::u8string_view aSid);

protected:
    virtual void            OnBeforeRQ          (GpRpcRqIfDesc& aRq) override;

private:
    std::u8string           iSid;
};

GpRpcClientSidGP::GpRpcClientSidGP (GpRpcCliTransport::SP aTransport) noexcept:
GpRpcClientGP(std::move(aTransport))
{
}

void    GpRpcClientSidGP::SetSID (std::u8string_view aSid)
{
    iSid = aSid;
}

}//namespace GPlatform
