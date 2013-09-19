# Adapted from linux-imx.inc, copyright (C) 2013 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-kernel/linux/linux-imx.inc

DESCRIPTION = "Linux kernel for i.MX6 Mini PC TV Sticks"

LOCALVERSION = "-4.1.0+yocto"
SRCREV = "6d821a3d5b910118b00f7907eeb029fcde1dd373"

SRC_URI = "git://github.com/ajayramaswamy/linux-imx-gk802.git;protocol=git;branch=gk802_3.0.35_4.1.0 \
           file://defconfig"

# Patches need for Yocto and not applied by Freescale when doing 4.1.0 branch
SRC_URI += "file://drm-vivante-Add-00-sufix-in-returned-bus-Id.patch \
	file://0001-perf-tools-Fix-getrusage-related-build-failure-on-gl.patch \
	file://0002-ARM-7668-1-fix-memset-related-crashes-caused-by-rece.patch \
	file://0003-ARM-7670-1-fix-the-memset-fix.patch \
	file://0004-ENGR00271136-Fix-build-break-when-CONFIG_CLK_DEBUG-i.patch \
	file://0005-ENGR00271359-Add-Multi-touch-support.patch \
	file://0006-Add-support-for-DVI-monitors.patch"

COMPATIBLE_MACHINE = "(ar802)"
