DESCRIPTION = "Shows an out-of-memory warning in the Openmoko panel"
DEPENDS = "libnotify"
RDEPENDS = "openmoko-dialer2"
PV = "0.0.0+svn${SVNREV}"
PR = "r0"

inherit openmoko-panel-plugin
