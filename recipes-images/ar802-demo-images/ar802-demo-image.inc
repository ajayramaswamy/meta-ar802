IMAGE_FEATURES += "package-management ssh-server-openssh x11-base debug-tweaks \
	nfs-server "
DISTRO_FEATURES += "pulseaudio"
WEB = "web-webkit"


LICENSE = "MIT"

inherit core-image

LICENSE_FLAGS_WHITELIST = "commercial" 
 
COMMERCIAL_AUDIO_PLUGINS ?= " \ 
	gst-plugins-ugly-mad \ 
	gst-plugins-ugly-mpegaudioparse \ 
" 
COMMERCIAL_VIDEO_PLUGINS ?= " \ 
	gst-plugins-ugly-mpeg2dec \ 
	gst-plugins-ugly-mpegstream \ 
	gst-plugins-bad-mpegvideoparse \ 
" 
CORE_IMAGE_EXTRA_INSTALL += " \ 
	packagegroup-fsl-gstreamer \ 
	gst-plugins-base-videotestsrc \ 
	gst-plugins-bad-fbdevsink \ 
	gst-ffmpeg alsa-utils \ 
	gst-plugins-good-isomp4 \ 
	packagegroup-fsl-gstreamer \
	packagegroup-fsl-tools-testapps \
	packagegroup-fsl-tools-benchmark \
	fsl-gui-extrafiles \
	cpufrequtils \
	nano \
" 

IMAGE_LINGUAS = " "


#copy_uimage_and_bootscript() {
#        mkdir -p "${IMAGE_ROOTFS}/boot"
#        cp "${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE}-${MACHINE}.bin" "${IMAGE_ROOTFS}/boot/${KERNEL_IMAGETYPE}"
#        mkimage -A arm -O linux -a 0 -e 0 -T script -C none -n "CuBox boot script for SD card" -d "${FILE_DIRNAME}/../../conf/boot/boot.script" "${IMAGE_ROOTFS}/boot/boot.scr"
#}


#ROOTFS_POSTPROCESS_COMMAND += "copy_uimage_and_bootscript ; "

