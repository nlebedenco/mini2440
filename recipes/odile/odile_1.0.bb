require odile.inc

do_install () {
    install -d ${D}${bindir}/
    install -m 0755 ${S}/hello ${D}${bindir}/
}
FILES_${PN} = "${bindir}/hello"
