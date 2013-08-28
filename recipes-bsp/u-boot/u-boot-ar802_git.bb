require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=1707d6db1d42237583f50183a5651ecb"
COMPATIBLE_MACHINE = "(ar802)"

PROVIDES = "u-boot"

PV = "v2013.04+git${SRCPV}"

SRCREV = "3bfbc1ca7d2b9c2b4920ff60012faa51c1fabe29"
SRC_URI = "git://github.com/ajayramaswamy/u-boot-gk802.git;protocol=git;branch=yocto-gk802"


S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MACHINE_ARCH}"
