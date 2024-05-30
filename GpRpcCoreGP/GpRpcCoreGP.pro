# ----------- Config -----------
TEMPLATE        = lib
#CONFIG        += staticlib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=acb1415b-e079-41d4-4a3a-78cd0e8dfd31
PACKET_NAME     = GpRpcCoreGP
DEFINES        += GP_RPC_CORE_GP_LIBRARY
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
    GpRpcClientGP.cpp \
    GpRpcClientSidGP.cpp \
    GpRpcCoreGPLib.cpp \
    GpRpcMethodDetectorJsonFactoryGP.cpp \
    GpRpcMethodDetectorJsonGP.cpp \
    GpRpcMethodNotFoundExceptionCodeGP.cpp \
    GpRpcMethodNotFoundExceptionGP.cpp \
    GpRpcMethodNotFoundManagerGP.cpp \
    GpRpcMethodNotFoundThrowerGP.cpp \
    GpRpcMethodsManagerGP.cpp \
    GpRpcPropValidationResDesc.cpp \
    RqRs/GpRpcRqGPDesc.cpp \
    RqRs/GpRpcRsGPDesc.cpp \
    RqRs/GpRpcRsResultGPDesc.cpp \
    RqRs/GpRpcRsResultItemsException.cpp

HEADERS += \
    GpRpcClientGP.hpp \
    GpRpcClientSidGP.hpp \
    GpRpcCoreGPLib.hpp \
    GpRpcCoreGP_global.hpp \
    GpRpcMethodDetectorJsonFactoryGP.hpp \
    GpRpcMethodDetectorJsonGP.hpp \
    GpRpcMethodGP.hpp \
    GpRpcMethodNotFoundExceptionCodeGP.hpp \
    GpRpcMethodNotFoundExceptionGP.hpp \
    GpRpcMethodNotFoundManagerGP.hpp \
    GpRpcMethodNotFoundThrowerGP.hpp \
    GpRpcMethodsManagerGP.hpp \
    GpRpcPropValidationResDesc.hpp \
    RqRs/GpRpcRqGPDesc.hpp \
    RqRs/GpRpcRsGPDesc.hpp \
    RqRs/GpRpcRsResultGPDesc.hpp \
    RqRs/GpRpcRsResultItemsException.hpp \
    RqRs/GpRpcRsResultItemsManager.hpp
