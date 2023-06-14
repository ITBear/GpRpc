TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./GpRpcCore \
		./GpRpcCoreJson \
		./GpRpcCoreGP \
		./GpRpcHttp \
		./GpRpcUtils
} else:os_android {
	SUBDIRS += \
		./GpRpcCore \
		./GpRpcCoreJson \
		./GpRpcCoreGP \
		./GpRpcHttp \
		./GpRpcUtils
} else:os_ios {
	SUBDIRS += \
		./GpRpcCore \
		./GpRpcCoreJson \
		./GpRpcCoreGP \
		./GpRpcHttp \
		./GpRpcUtils
} else:os_windows {
	SUBDIRS += \
		./GpRpcCore \
		./GpRpcCoreJson \
		./GpRpcCoreGP \
		./GpRpcHttp \
		./GpRpcUtils
} else:os_macx {
	SUBDIRS += \
		./GpRpcCore \
		./GpRpcCoreJson \
		./GpRpcCoreGP \
		./GpRpcHttp \
		./GpRpcUtils
} else:os_browser {
	SUBDIRS +=
} else {
	error("Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser, os_baremetal")
}

CONFIG += ordered
