TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=3370694e-8eae-481f-675c-e8c5ed9d45c7
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_RPC_UTILS_LIBRARY
PACKET_NAME     = GpRpcUtils
DIR_LEVEL       = ./../..

include(../../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES += \
	Generators/Documentation/GpRpcDocGenerator.cpp

HEADERS += \
	Generators/Documentation/GpRpcDocGenerator.hpp \
	GpRpcUtils_global.hpp
