DESCRIPTION = "GNU Midnight Commander is a file \
manager for free operating systems."
HOMEPAGE = "http://www.ibiblio.org/mc/"
LICENSE = "GPLv2"
SECTION = "console/utils"
PRIORITY = "optional"
DEPENDS = "ncurses glib-2.0 glib-2.0-native"
RDEPENDS = "ncurses-terminfo"

SRC_URI = "http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/mc-${PV}.tar.gz"

inherit autotools

EXTRA_OECONF = "--libexecdir=${libdir} --disable-glibtest --without-x --without-samba \
--without-nfs --without-gpm-mouse --with-screen=ncurses"

PACKAGES += "${PN}-extfs ${PN}-hilite"
FILES_${PN} = "${bindir}/ ${libdir}/ ${datadir}/mc/*.charsets ${datadir}/mc/*.ext ${datadir}/mc/*.hint ${datadir}/mc/*.hlp ${datadir}/mc/*.lib ${datadir}/mc/*.menu ${datadir}/mc/*.rc ${datadir}/mc/bin /etc/profile.d"
FILES_${PN}-extfs = "${datadir}/mc/extfs/"
FILES_${PN}-hilite = "${datadir}/mc/syntax/"
RRECOMMENDS_${PN} += "${PN}-extfs ${PN}-hilite"
RDEPENDS_${PN}-extfs = "${PN}"
RDEPENDS_${PN}-hilite = "${PN}"
PACKAGE_ARCH_${PN}-extfs = "all"
PACKAGE_ARCH_${PN}-hilite = "all"

export CC_FOR_BUILD = "${BUILD_CC}"
export CFLAGS_FOR_BUILD = "${BUILD_CFLAGS}"
export LD_FOR_BUILD = "${BUILD_CC}"
do_compile_prepend() {
	export GLIB_CFLAGS_FOR_BUILD="`${STAGING_BINDIR_NATIVE}/pkg-config --cflags glib-2.0`"
	export GLIB_LIBS_FOR_BUILD="`${STAGING_BINDIR_NATIVE}/pkg-config --libs glib-2.0`"
}

do_install_append() {
	if test -f ${D}${datadir}/mc/bin/mc.sh ; then
		mkdir -p ${D}/etc/profile.d
		mv ${D}${datadir}/mc/bin/mc.*sh ${D}/etc/profile.d
	fi
}

python populate_packages_prepend () {
	mcdir   = bb.data.expand('${datadir}/mc', d)
	do_split_packages(d, mcdir, '^mc\.[hm][ile][npn].*\.(.*)$',
		output_pattern='mc-locale-%s',
		description='%s translation for mc')
}
