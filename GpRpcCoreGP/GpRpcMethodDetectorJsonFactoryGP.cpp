#include "GpRpcMethodDetectorJsonFactoryGP.hpp"
#include "GpRpcMethodDetectorJsonGP.hpp"

namespace GPlatform::RPC {

GpRpcMethodDetectorJsonFactoryGP::GpRpcMethodDetectorJsonFactoryGP (void) noexcept
{
}

GpRpcMethodDetectorJsonFactoryGP::~GpRpcMethodDetectorJsonFactoryGP (void) noexcept
{
}

GpRpcMethodDetector::SP GpRpcMethodDetectorJsonFactoryGP::NewInstance (GpSpanPtrByteR aData) const
{
    return MakeSP<GpRpcMethodDetectorJsonGP>(aData.AsStringView());
}

}//namespace GPlatform::RPC
