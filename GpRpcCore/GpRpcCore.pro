TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=a38cfdc0-da92-4899-9523-002751c6b88e
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_RPC_CORE_LIBRARY
PACKET_NAME     = GpRpcCore
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES += \
    RqRs/GpRpcRqIfDesc.cpp \
    RqRs/GpRpcRsIfDesc.cpp \
    RqRs/GpRpcRsResultIfDesc.cpp \
    RqRs/GpRpcVoidDesc.cpp \
    Server/GpRpcMethodFactory.cpp \
    Server/GpRpcMethodsManager.cpp \
    Server/GpRpcMethodsManagersGroup.cpp

HEADERS += \
    Client/GpRpcCliTransport.hpp \
    Client/GpRpcCliTransportFactory.hpp \
    Client/GpRpcClient.hpp \
    Client/GpRpcClientRaw.hpp \
    GpRpcCore.hpp \
    GpRpcCore_global.hpp \
    RqRs/GpRpcRqIfDesc.hpp \
    RqRs/GpRpcRqRs.hpp \
    RqRs/GpRpcRsIfDesc.hpp \
    RqRs/GpRpcRsResultIfDesc.hpp \
    RqRs/GpRpcVoidDesc.hpp \
    Server/GpRpcMethod.hpp \
    Server/GpRpcMethodDetector.hpp \
    Server/GpRpcMethodDetectorFactory.hpp \
    Server/GpRpcMethodFactory.hpp \
    Server/GpRpcMethodNotFoundThrower.hpp \
    Server/GpRpcMethodsManager.hpp \
    Server/GpRpcMethodsManagersGroup.hpp \
    Server/GpRpcMethodsRegister.hpp \
    Server/GpRpcServer.hpp
