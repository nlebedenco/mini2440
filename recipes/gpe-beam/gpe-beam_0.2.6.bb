require ${PN}.inc

RDEPENDS = "libopenobex-1.0-1 irda-utils"
PR = "r1"

SRC_URI += "file://vcard-send.patch;patch=1;pnum=0"

inherit gpe
