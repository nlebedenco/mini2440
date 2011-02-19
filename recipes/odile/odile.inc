DESCRIPTION = "Odile Main Application"
HOMEPAGE = ""
LICENSE = ""
PR = "r0"
DEPENDS = ""
PROVIDES = "odile"

# Need these two lines to stop OE's attempts to fetch local git repo
# from http mirror
CVS_TARBALL_STASH = ""
SRC_TARBALL_STASH = ""

SRC_URI = "git:///home/notroot/odile;protocol=file;branch=master"
SRCREV = "${AUTOREV}"
S = "${WORKDIR}/git"
 
