TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=acb1415b-e079-41d4-4a3a-78cd0e8dfd31
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_RPC_CORE_GP_LIBRARY
PACKET_NAME     = GpRpcCoreGP
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES += \
    GpRpcClientGP.cpp \
    GpRpcClientSidGP.cpp \
    GpRpcMethodDetectorJsonFactoryGP.cpp \
    GpRpcMethodDetectorJsonGP.cpp \
    GpRpcMethodNotFoundExceptionCodeGP.cpp \
    GpRpcMethodNotFoundExceptionGP.cpp \
    GpRpcMethodNotFoundManagerGP.cpp \
    GpRpcMethodNotFoundThrowerGP.cpp \
    GpRpcMethodsManagerGP.cpp \
    RqRs/GpRpcRqGPDesc.cpp \
    RqRs/GpRpcRsGPDesc.cpp \
    RqRs/GpRpcRsResultGPDesc.cpp

HEADERS += \
    GpRpcClientGP.hpp \
    GpRpcClientSidGP.hpp \
    GpRpcCoreGP.hpp \
    GpRpcCoreGP_global.hpp \
    GpRpcMethodDetectorJsonFactoryGP.hpp \
    GpRpcMethodDetectorJsonGP.hpp \
    GpRpcMethodGP.hpp \
    GpRpcMethodNotFoundExceptionCodeGP.hpp \
    GpRpcMethodNotFoundExceptionGP.hpp \
    GpRpcMethodNotFoundManagerGP.hpp \
    GpRpcMethodNotFoundThrowerGP.hpp \
    GpRpcMethodsManagerGP.hpp \
    RqRs/GpRpcRqGPDesc.hpp \
    RqRs/GpRpcRqRsGP.hpp \
    RqRs/GpRpcRsGPDesc.hpp \
    RqRs/GpRpcRsResultGPDesc.hpp
