#include "GpRpcMethodDetectorJsonGP.hpp"
#include "../../GpJson/GpJsonSerializerCtx.hpp"

namespace GPlatform {

GpRpcMethodDetectorJsonGP::~GpRpcMethodDetectorJsonGP (void) noexcept
{
}

GpRpcMethodDetector::ResT   GpRpcMethodDetectorJsonGP::DetectApiMethodName (void) const
{
    GpJsonSerializerCtx::SP rqCtxSP = MakeSP<GpJsonSerializerCtx>();
    GpJsonSerializerCtx&    rqCtx   = rqCtxSP.Vn();

    rqCtx.Parse(iJsonStr);

    const auto methodOpt = rqCtx.FindMemberStr("method");

    return
    {
        methodOpt.has_value() ? methodOpt.value() : "",
        rqCtxSP
    };
}

}// namespace GPlatform
