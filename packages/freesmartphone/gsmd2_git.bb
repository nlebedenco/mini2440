DESCRIPTION = "GSM 07.07 phone server"
HOMEPAGE = "http://www.freesmartphone.org/mediawiki/index.php/Implementations/gsm0710muxd"
AUTHOR = "Ixonos"
SECTION = "console/network"
DEPENDS = "dbus dbus-glib"
RDEPENDS = "gsm0710muxd"
LICENSE = "GPL"
PV = "0.0.0+gitr${SRCREV}"
PR = "r0"

SRC_URI = "${FREESMARTPHONE_GIT}/gsmd2.git;protocol=git;branch=master"
S = "${WORKDIR}/git"

inherit autotools