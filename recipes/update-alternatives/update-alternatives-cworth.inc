LICENSE = "GPL"
SECTION = "base"
SRC_URI = "${HANDHELDS_CVS};module=familiar/dist/ipkg;tag=${@'V' + bb.data.getVar('PV',d,1).replace('.', '-')}"
S = "${WORKDIR}/ipkg/C"
PACKAGE_ARCH = "all"

PR = "r1"
