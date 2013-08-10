require recipes-bsp/u-boot/u-boot.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://COPYING;md5=1707d6db1d42237583f50183a5651ecb"
COMPATIBLE_MACHINE = "(gk802)"
DEPENDS = "u-boot-mkimage-native"

PROVIDES = "u-boot"

PV = "v2013.04+git${SRCPV}"

SRCREV = "3bfbc1ca7d2b9c2b4920ff60012faa51c1fabe29"
SRC_URI = "git://github.com/ajayramaswamy/u-boot-gk802.git;protocol=git"

SRC_URI += "file://boot.txt \
	    file://t2s.sh"

S = "${WORKDIR}/git"

do_mkimage () {
    uboot-mkimage  -A arm -O linux -T script -C none -a 0 -e 0 \
                   -n "boot script" -d ../boot.txt ../boot.scr
}

do_install_append () {
	install -d ${D}/boot
	install -m 0644 ${WORKDIR}/boot.txt ${D}/boot/boot.txt
	install -m 0644 ${WORKDIR}/boot.scr ${D}/boot/boot.scr
	install -m 0755 ${WORKDIR}/t2s.sh ${D}/boot/t2s.sh
}

addtask mkimage after do_compile before do_install

PACKAGE_ARCH = "${MACHINE_ARCH}"
