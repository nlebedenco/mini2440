require odile.inc
inherit native

do_stage() {
    install -m 0755 ${S}/hello ${STAGING_BINDIR_NATIVE}/
}

do_install () {
    :
}




