#pragma once

#include "GpRpcCliTransport.hpp"

namespace GPlatform {

class GpRpcCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcCliTransportFactory)
    CLASS_DD(GpRpcCliTransportFactory)

protected:
                                    GpRpcCliTransportFactory    (void) noexcept {}

public:
    virtual                         ~GpRpcCliTransportFactory   (void) noexcept {}

    virtual GpRpcCliTransport::SP   NewInstance                 (void) const = 0;
};

}// namespace GPlatform
