TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=829f25d3-bc89-4f1c-a950-1dee504c8b38
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_RPC_HTTP_LIBRARY
PACKET_NAME     = GpRpcHttp
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES += \
    Client/GpRpcCliTransportHttp.cpp \
    Client/GpRpcCliTransportHttpFactory.cpp \
    Server/GpRpcSrvRequestHandlerHttp.cpp \
    Server/GpRpcSrvRequestHandlerHttpFactory.cpp

HEADERS += \
    Client/GpRpcCliTransportHttp.hpp \
    Client/GpRpcCliTransportHttpFactory.hpp \
    GpRpcHttp.hpp \
    GpRpcHttp_global.hpp \
    Server/GpRpcSrvRequestHandlerHttp.hpp \
    Server/GpRpcSrvRequestHandlerHttpFactory.hpp
