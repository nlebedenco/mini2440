require psplash.inc
require psplash-ua.inc

ALTERNATIVE_PRIORITY = "20"

SRC_URI = "svn://svn.o-hand.com/repos/misc/trunk;module=psplash;proto=http \
          file://logo-math.patch;patch=1 \
          file://configurability.patch;patch=1 \
          file://psplash-hand.png \
          file://psplash-bar.png \
          file://psplash-default \
          file://psplash-init"
S = "${WORKDIR}/psplash"


do_configure_prepend() {
    ${S}/make-image-header.sh ${WORKDIR}/psplash-hand.png HAND
    ${S}/make-image-header.sh ${WORKDIR}/psplash-bar.png BAR
    install -m 0644 ${S}/psplash-hand-img.h ${WORKDIR}/
    install -m 0644 ${S}/psplash-bar-img.h ${WORKDIR}/
}

