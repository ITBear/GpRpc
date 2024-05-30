#include "GpRpcMethodDetectorJsonFactoryGP.hpp"
#include "GpRpcMethodDetectorJsonGP.hpp"

namespace GPlatform {

GpRpcMethodDetectorJsonFactoryGP::GpRpcMethodDetectorJsonFactoryGP (void) noexcept
{
}

GpRpcMethodDetectorJsonFactoryGP::~GpRpcMethodDetectorJsonFactoryGP (void) noexcept
{
}

GpRpcMethodDetector::SP GpRpcMethodDetectorJsonFactoryGP::NewInstance (GpSpanCharRW aData) const
{
    return MakeSP<GpRpcMethodDetectorJsonGP>(std::move(aData));
}

}// namespace GPlatform
