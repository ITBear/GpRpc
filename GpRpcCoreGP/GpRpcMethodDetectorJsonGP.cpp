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

    rqCtx.Init(iJsonStr);

    return {rqCtx.FindMemberStr(u8"method"), rqCtxSP};
}

}//namespace GPlatform
