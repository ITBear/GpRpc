# ----------- Config -----------
TEMPLATE        = lib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=829f25d3-bc89-4f1c-a950-1dee504c8b38
PACKET_NAME     = GpRpcHttp
DEFINES        += GP_RPC_HTTP_LIBRARY
_VER_MAJ        = 2
_VER_MIN        = 1
_VER_PAT        = 6
DIR_LEVEL       = ./../..

include($$DIR_LEVEL/../QtGlobalPro.pri)

equals(var_link, "static") {
	CONFIG += staticlib
}

# ----------- Libraries -----------
equals(var_os, "windows") {
	LIBS += -lGpRpcCore$$TARGET_POSTFIX
	LIBS += -lGpNetworkHttpCore$$TARGET_POSTFIX
	LIBS += -lGpNetworkCore$$TARGET_POSTFIX
	LIBS += -lGpReflection$$TARGET_POSTFIX
	LIBS += -lGpUtils$$TARGET_POSTFIX
}

equals(var_os, "linux") {
	LIBS += -lGpRpcCore$$TARGET_POSTFIX
	LIBS += -lGpNetworkHttpCore$$TARGET_POSTFIX
	LIBS += -lGpNetworkCore$$TARGET_POSTFIX
	LIBS += -lGpReflection$$TARGET_POSTFIX
	LIBS += -lGpUtils$$TARGET_POSTFIX

	LIBS += -lfmt
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
