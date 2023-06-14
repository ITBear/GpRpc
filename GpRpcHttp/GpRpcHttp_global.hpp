#pragma once

#include "../../GpCore2/GpUtils/Macro/GpMacroImportExport.hpp"

#if defined(GP_RPC_HTTP_LIBRARY)
    #define GP_RPC_HTTP_API GP_DECL_EXPORT
#else
    #define GP_RPC_HTTP_API GP_DECL_IMPORT
#endif
