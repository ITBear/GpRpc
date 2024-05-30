# ----------- Config -----------
TEMPLATE        = lib
#CONFIG        += staticlib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=a3e7ad7e-033b-4646-b389-24f03d09ea9e
PACKET_NAME     = GpRpcCoreJson
DEFINES        += GP_RPC_CORE_JSON_LIBRARY
_VER_MAJ        = 2
_VER_MIN        = 1
_VER_PAT        = 5
DIR_LEVEL       = ./../..

include($$DIR_LEVEL/../QtGlobalPro.pri)

# ----------- Libraries -----------
os_windows{
}

os_linux{
}

# ----------- Sources and headers -----------
SOURCES += \
    RqRs/GpRpcRqJsonDesc.cpp \
    RqRs/GpRpcRsJsonDesc.cpp \
    RqRs/GpRpcRsResultJsonDesc.cpp

HEADERS += \
    GpRpcCoreJson.hpp \
    GpRpcCoreJson_global.hpp \
    RqRs/GpRpcRqJsonDesc.hpp \
    RqRs/GpRpcRqRsJson.hpp \
    RqRs/GpRpcRsJsonDesc.hpp \
    RqRs/GpRpcRsResultJsonDesc.hpp
