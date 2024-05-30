# ----------- Config -----------
TEMPLATE        = lib
#CONFIG        += staticlib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=a38cfdc0-da92-4899-9523-002751c6b88e
PACKET_NAME     = GpRpcCore
DEFINES        += GP_RPC_CORE_LIBRARY
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
    GpRpcCoreLib.cpp \
    RqRs/GpRpcRqIfDesc.cpp \
    RqRs/GpRpcRsIfDesc.cpp \
    RqRs/GpRpcVoidDesc.cpp \
    Server/GpRpcMethod.cpp \
    Server/GpRpcMethodFactory.cpp \
    Server/GpRpcMethodsManager.cpp \
    Server/GpRpcMethodsManagersGroup.cpp

HEADERS += \
    Client/GpRpcCliTransport.hpp \
    Client/GpRpcCliTransportFactory.hpp \
    Client/GpRpcClient.hpp \
    GpRpcCoreLib.hpp \
    GpRpcCore_global.hpp \
    RqRs/GpRpcRqIfDesc.hpp \
    RqRs/GpRpcRsIfDesc.hpp \
    RqRs/GpRpcVoidDesc.hpp \
    Server/GpRpcMethod.hpp \
    Server/GpRpcMethodDetector.hpp \
    Server/GpRpcMethodDetectorFactory.hpp \
    Server/GpRpcMethodFactory.hpp \
    Server/GpRpcMethodNotFoundThrower.hpp \
    Server/GpRpcMethodsManager.hpp \
    Server/GpRpcMethodsManagersGroup.hpp \
    Server/GpRpcServer.hpp
