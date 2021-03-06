# general configuration file for freezing a distribution
#
# If freeze.conf is included (require conf/distro/include/freeze.inc) in the
# distro conf file it will define BBFILES from the information in
# ${DISTRO}-bbfiles.conf or ${DISTRO}-packages.conf (whichever
# exists in that order of preference.)
#
# NOTE that these conf files use ${PKGDIR} and therefore that
# variable must be defined before this file is included, or the
# definition below (${TOPDIR}/openmebedded) must be correct.
#
PKGDIR ?= "${TOPDIR}/openembedded"
FROZEN_DIR ?= "/non/-existent/-directory/-for/-security"

# Pull in the frozen definitions (if they exist)  The multiple
# includes allow the frozen file to be stored alongside local.conf
# and in a distro-specific frozen directory - the former take
# precedence over the latter.
include conf/${DISTRO}-packages.conf
include ${FROZEN_DIR}/${DISTRO}-packages.conf

include conf/${DISTRO}-bbfiles.conf
include ${FROZEN_DIR}/${DISTRO}-bbfiles.conf
