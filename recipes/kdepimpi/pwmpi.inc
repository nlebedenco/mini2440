DEPENDS_append = "kdepimpi-${PV}"

SUBDIRS="pwmanager/libcrypt/mpi  \
        pwmanager/libcrypt/error  \
        pwmanager/libcrypt/cipher  \
        pwmanager/pwmanager \
        "
export OE_QMAKE_LINK="${CXX}"

OE_QMAKE_CFLAGS_prepend="-I${S}/pwmanager/libcrypt/crypt "
EXTRA_QMAKEVARS_POST += " \
INCLUDEPATH+=${STAGING_INCDIR}/kdepimpi/ \
LIBS+=-L${STAGING_LIBDIR}/kdepimpi/ \
"

do_configure_prepend() {
}

do_stage() {
}

do_unstage() {
}

do_install() {
    install -d ${D}${bindir} \
               ${D}${palmtopdir}/apps/Applications \
               ${D}${palmtopdir}/pics/kdepim/pwmanager/icons16 \
               ${D}${palmtopdir}/pics/kdepim/pwmanager/icons22

    install -m 0644 ${S}/bin/kdepim/pwmanager/*.* ${D}${palmtopdir}/pics/kdepim/pwmanager
    install -m 0644 ${S}/bin/kdepim/pwmanager/icons16/*.png ${D}${palmtopdir}/pics/kdepim/pwmanager/icons16
    install -m 0644 ${S}/bin/kdepim/pwmanager/icons22/*.png ${D}${palmtopdir}/pics/kdepim/pwmanager/icons22
    install -m 0644 pwmanager/pwmanager/pwmanager.desktop ${D}${palmtopdir}/apps/Applications/pwmanager.desktop

    install -m 0755 ${S}/dest/pwmpi ${D}${bindir}
}

FILES_${PN} = "${palmtopdir} ${bindir}"
