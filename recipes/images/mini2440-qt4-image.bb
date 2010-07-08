#Mini2440 Qt4 image
require mini2440-image.bb

DEPENDS += "qt4-embedded"

IMAGE_INSTALL += "qt4-embedded"

export IMAGE_BASENAME = "mini2440-qt4-image"

