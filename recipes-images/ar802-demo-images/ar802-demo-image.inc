LICENSE = "MIT"
inherit core-image

IMAGE_FEATURES += "package-management \
	ssh-server-openssh \
	x11-base debug-tweaks \
	nfs-server \
	"

DISTRO_FEATURES += "pulseaudio"
WEB = "web-webkit"

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
	u-boot-mkimage \
" 

IMAGE_LINGUAS = " "

copy_uimage_and_bootscript() {
        mkdir -p "${IMAGE_ROOTFS}/boot"
	install -m 0644 "${FILE_DIRNAME}/boot/boot.txt" "${IMAGE_ROOTFS}/boot/boot.txt"
	install -m 0755 "${FILE_DIRNAME}/boot/t2s.sh" "${IMAGE_ROOTFS}/boot/t2s.sh"
	mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n 'Boot setup script for SD' -d "${IMAGE_ROOTFS}/boot/boot.txt" "${IMAGE_ROOTFS}/boot/boot.scr"
}

ROOTFS_POSTPROCESS_COMMAND += "copy_uimage_and_bootscript ; "
