#pragma once

#include <GpCore2/GpUtils/Macro/GpMacroImportExport.hpp>

#if defined(GP_RPC_CORE_LIBRARY)
    #define GP_RPC_CORE_API GP_DECL_EXPORT
#else
    #define GP_RPC_CORE_API GP_DECL_IMPORT
#endif
