#pragma once

#include "GpRpcCliTransportFactory.hpp"

namespace GPlatform::RPC {

class GpRpcClient
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpRpcClient)
    CLASS_DD(GpRpcClient)

protected:
    inline                          GpRpcClient     (GpRpcCliTransport::SP aTransport) noexcept;

public:
    virtual                         ~GpRpcClient    (void) noexcept {}

    GpRpcCliTransport::SP           Transport       (void) noexcept {return iTransport;}

protected:
    GpRpcCliTransport&              _Transport      (void) noexcept {return iTransport.Vn();}

private:
    GpRpcCliTransport::SP           iTransport;
};

GpRpcClient::GpRpcClient (GpRpcCliTransport::SP aTransport) noexcept:
iTransport(std::move(aTransport))
{
}

}//namespace GPlatform::RPC
