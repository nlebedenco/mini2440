#Mini2440 Erlang + Qt4 image
require mini2440-erlang-image.bb

DEPENDS += "qt4-embedded"

IMAGE_INSTALL += "qt4-embedded \
                  qt4-embedded-fonts \
                  qt4-embedded-plugin-mousedriver-tslib"

export IMAGE_BASENAME = "mini2440-erlang-qt4-image"

