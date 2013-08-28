# Adapted from linux-imx.inc, copyright (C) 2013 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

require recipes-kernel/linux/linux-imx.inc

DESCRIPTION = "Linux kernel for i.MX6 Mini PC TV Sticks"

LOCALVERSION = "-4.0.0+yocto"
SRCREV = "c2817892960b2fd14189c92adf61f97184fac092"

SRC_URI = "git://github.com/ajayramaswamy/linux-imx-gk802.git;protocol=git;branch=gk802_3.0.35_4.0.0 \
           file://defconfig"

# GPU support patches
SRC_URI += "file://drm-vivante-Add-00-sufix-in-returned-bus-Id.patch \
            file://0001-ENGR00255688-4.6.9p11.1-gpu-GPU-Kernel-driver-integr.patch \
            file://0002-ENGR00265465-gpu-Add-global-value-for-minimum-3D-clo.patch \
            file://0003-ENGR00261814-4-gpu-use-new-PU-power-on-off-interface.patch \
            file://0004-ENGR00264288-1-GPU-Integrate-4.6.9p12-release-kernel.patch \
            file://0005-ENGR00264275-GPU-Correct-suspend-resume-calling-afte.patch \
            file://0006-ENGR00265130-gpu-Correct-section-mismatch-in-gpu-ker.patch"

COMPATIBLE_MACHINE = "(ar802)"
