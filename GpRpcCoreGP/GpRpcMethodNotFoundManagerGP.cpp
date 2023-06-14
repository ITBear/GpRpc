#include "GpRpcMethodNotFoundManagerGP.hpp"
#include "../../GpCore2/GpReflection/GpReflectManager.hpp"
#include "../../GpCore2/GpUtils/Exceptions/GpException.hpp"

namespace GPlatform {

using gp_rcp_method_not_found_default_rs_data   = GpRpcVoidDesc::SP;
using gp_rcp_method_not_found_default_rs_result = GpRpcRsResultGPDesc::SP;

GP_RPC_RS(GP_RPC_CORE_GP_API, gp_rcp_method_not_found_default, "8d003f95-eee4-42b4-b612-e51058fca267"_uuid)
GP_RPC_RS_IMPL(gp_rcp_method_not_found_default)

GpRpcMethodNotFoundManagerGP::GpRpcMethodNotFoundManagerGP (void) noexcept
{
}

GpRpcMethodNotFoundManagerGP::~GpRpcMethodNotFoundManagerGP (void) noexcept
{
}

GpRpcRsIfDesc::SP   GpRpcMethodNotFoundManagerGP::NewDefaultRs (void) const
{
    return MakeSP<gp_rcp_method_not_found_default_rs>();
}

void    GpRpcMethodNotFoundManagerGP::OnInit (void)
{
}

}//namespace GPlatform
