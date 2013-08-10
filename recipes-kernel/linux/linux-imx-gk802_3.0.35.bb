# Adapted from linux-imx.inc, copyright (C) 2013 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-kernel/linux/linux-imx.inc

DESCRIPTION = "Linux kernel for i.MX6 Mini PC TV Sticks"

SRC_URI = "git://github.com/ajayramaswamy/linux-imx-gk802.git \
           file://defconfig"


LOCALVERSION = "-4.0.0+yocto"
SRCREV = "97e29ab1983eee1d2755af8ed523ee129e77bea3"

COMPATIBLE_MACHINE = "(mx6)"
