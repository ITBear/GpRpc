# ----------- Config -----------
TEMPLATE        = lib
#CONFIG        += staticlib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=829f25d3-bc89-4f1c-a950-1dee504c8b38
PACKET_NAME     = GpRpcHttp
DEFINES        += GP_RPC_HTTP_LIBRARY
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
    Client/GpRpcCliTransportHttp.cpp \
    Client/GpRpcCliTransportHttpFactory.cpp \
    GpRpcHttpLib.cpp \
    Server/GpRpcSrvRequestHandlerHttp.cpp \
    Server/GpRpcSrvRequestHandlerHttpFactory.cpp

HEADERS += \
    Client/GpRpcCliTransportHttp.hpp \
    Client/GpRpcCliTransportHttpFactory.hpp \
    GpRpcHttpLib.hpp \
    GpRpcHttp_global.hpp \
    Server/GpRpcSrvRequestHandlerHttp.hpp \
    Server/GpRpcSrvRequestHandlerHttpFactory.hpp
