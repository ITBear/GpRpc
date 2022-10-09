TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=a3e7ad7e-033b-4646-b389-24f03d09ea9e
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_RPC_CORE_JSON_LIBRARY
PACKET_NAME     = GpRpcCoreJson
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

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
