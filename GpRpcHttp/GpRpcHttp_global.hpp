#pragma once

#include "../GpRpcCore/GpRpcCore.hpp"
#include "../../GpNetwork/GpNetworkCore/GpNetworkCore.hpp"
#include "../../GpNetwork/GpNetworkHttp/GpNetworkHttpCore/GpNetworkHttpCore.hpp"

#if defined(GP_RPC_HTTP_LIBRARY)
    #define GP_RPC_HTTP_API GP_DECL_EXPORT
#else
    #define GP_RPC_HTTP_API GP_DECL_IMPORT
#endif
