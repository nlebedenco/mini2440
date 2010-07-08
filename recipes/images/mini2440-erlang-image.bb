#Erlang image
require mini2440-image.bb

DEPENDS += "erlang"

IMAGE_INSTALL += "erlang"

export IMAGE_BASENAME = "mini2440-erlang-image"

