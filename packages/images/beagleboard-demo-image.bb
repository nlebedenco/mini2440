# Demo image for beagleboard

XSERVER ?= "xserver-kdrive-fbdev"

ANGSTROM_EXTRA_INSTALL ?= ""

export IMAGE_BASENAME = "Beagleboard-demo-image"

DEPENDS = "task-base"
IMAGE_INSTALL = "\
    ${XSERVER} \
    task-base-extended \
    angstrom-x11-base-depends \
    angstrom-gpe-task-base \
    angstrom-gpe-task-settings \
    ${ANGSTROM_EXTRA_INSTALL} \
    angstrom-zeroconf-audio \
    gpe-scap \
    psplash \
    e-wm exhibit \
    xterm xmms epiphany-firefox-replacement \
    hicolor-icon-theme gnome-icon-theme \
    jaaa octave nmap iperf gnuplot \
    abiword gnumeric gimp minimo \
    powertop \
"

IMAGE_PREPROCESS_COMMAND = "create_etc_timestamp"

#zap root password for release images
ROOTFS_POSTPROCESS_COMMAND += '${@base_conditional("DISTRO_TYPE", "release", "zap_root_password; ", "",d)}'

inherit image