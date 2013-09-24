LICENSE = "MIT"
inherit core-image

EXTRA_IMAGE_FEATURES += " \
	package-management \
	ssh-server-openssh \
	splash \
	hwcodecs \
	x11-base debug-tweaks \
	nfs-server \
    	tools-debug \
    	tools-profile \
	tools-testapps \
    	qt4-pkgs \
"

DISTRO_FEATURES += "pulseaudio pam "
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
	packagegroup-core-basic \
	packagegroup-core-lsb \
	packagegroup-fsl-gstreamer \ 
	gst-plugins-base-videotestsrc \ 
	gst-plugins-bad-fbdevsink \ 
	gst-ffmpeg \
	alsa-utils \ 
	gst-plugins-good-isomp4 \ 
	packagegroup-fsl-gstreamer \
	packagegroup-fsl-tools-testapps \
	packagegroup-fsl-tools-benchmark \
    	packagegroup-qt-in-use-demos \
    	qt4-plugin-phonon-backend-gstreamer \
    	qt4-demos \
    	qt4-examples \
	fsl-gui-extrafiles \
	cpufrequtils \
	nano \
	vim \
	u-boot-mkimage \
	packagegroup-fonts-truetype \
	packagegroup-core-buildessential \
	packagegroup-core-tools-testapps \
	mplayer2 \
	rfkill \
	rtorrent \
	samba \
	screen \
	apache2 \
	modphp \
	php \
	bigbuckbunny-480p \
	bigbuckbunny-720p \
	bigbuckbunny-1080p \
	autofs \
	vsftpd \
" 

IMAGE_LINGUAS = " "

copy_uimage_and_bootscript() {
        mkdir -p "${IMAGE_ROOTFS}/boot"
	install -m 0644 "${FILE_DIRNAME}/boot/boot.txt" "${IMAGE_ROOTFS}/boot/boot.txt"
	install -m 0755 "${FILE_DIRNAME}/boot/t2s.sh" "${IMAGE_ROOTFS}/boot/t2s.sh"
	mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n 'Boot setup script for SD' -d "${IMAGE_ROOTFS}/boot/boot.txt" "${IMAGE_ROOTFS}/boot/boot.scr"
	mkdir -p "${IMAGE_ROOTFS}/etc/modprobe.d"
	install -m 0644 "${FILE_DIRNAME}/extra_files/rfkill.conf" "${IMAGE_ROOTFS}/etc/modprobe.d/rfkill.conf"
	mkdir -p "${IMAGE_ROOTFS}/home/root"
	install -m 0755 "${FILE_DIRNAME}/extra_files/cpustats" "${IMAGE_ROOTFS}/home/root/cpustats"
	install -m 0755 "${FILE_DIRNAME}/extra_files/gov_perf" "${IMAGE_ROOTFS}/home/root/gov_perf"
	install -m 0755 "${FILE_DIRNAME}/extra_files/gov_ondemand" "${IMAGE_ROOTFS}/home/root/gov_ondemand"
}

ROOTFS_POSTPROCESS_COMMAND += "copy_uimage_and_bootscript ; "

export IMAGE_BASENAME = "ar802-image"
