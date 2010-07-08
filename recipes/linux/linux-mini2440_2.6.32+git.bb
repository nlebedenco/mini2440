DESCRIPTION = "Linux Kernel for mini2440 development board"
SECTION = "kernel"
LICENSE = "GPL"
PR = "r2"

GGSRC = "http://www.xora.org.uk/oe/patches/"

SRCREV = "${AUTOREV}"

SRC_URI = "git://repo.or.cz/linux-2.6/mini2440.git;protocol=git;branch=mini2440-stable-v2.6.32 \
        file://01-fix_nand_bbt_detection.patch;patch=1 \
        file://02-fix_s3c2410_gpio_pullup_calls.patch;patch=1 \
        file://03-fix_drivers_gpio_direction.patch;patch=1 \
        file://04-gpj_support.patch;patch=1 \
        file://05-gpio_keys_as_optional_feature.patch;patch=1 \
        file://06-spi0_as_optional_feature.patch;patch=1 \
        file://07-disable_uneeded_pullups.patch;patch=1 \
        file://logo.png \
        file://defconfig-mini2440"

S = "${WORKDIR}/git"

KERNEL_IMAGETYPE = "uImage"
UBOOT_ENTRYPOINT = "30008000"

inherit kernel

COMPATIBLE_HOST = "arm.*-linux"
COMPATIBLE_MACHINE = "mini2440"

do_configure() {
    pngtopnm ${WORKDIR}/logo.png | ppmquant -fs 223 | pnmtoplainpnm > ${WORKDIR}/logo_linux_clut224.ppm
    install -m 0644 ${WORKDIR}/logo_linux_clut224.ppm ${S}/drivers/video/logo/logo_linux_clut224.ppm

    install ${WORKDIR}/defconfig-mini2440 ${S}/.config
    oe_runmake oldconfig
}

KERNEL_RELEASE = "2.6.32"
