PORTNAME=	u-boot
PORTVERSION=	2016.05
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Cross-build U-Boot loader for multiple boards

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc

BOARDS?=	am335x_boneblack \
		Cubieboard \
		orangepi_one \
		orangepi_pc \
		rpi

FILES?=		MLO \
		u-boot.bin \
		u-boot.img \
		u-boot-sunxi-with-spl.bin \

NO_ARCH=	yes

USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

do-configure:
.for BOARD in ${BOARDS}
	(cd ${WRKSRC} && mkdir -p build/${BOARD} && ${MAKE_CMD} O="build/${BOARD}" ${BOARD}_defconfig)
.endfor

do-build:
.for BOARD in ${BOARDS}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} O="build/${BOARD}" ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} ${ALL_TARGET})
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for BOARD in ${BOARDS}
	${MKDIR} ${STAGEDIR}${DATADIR}/${BOARD}
.  for F in ${FILES}
	(cd ${WRKSRC}/build/${BOARD}; if [ -e ${F} ]; then ${INSTALL_DATA} ${F} ${STAGEDIR}${DATADIR}/${BOARD}/; else true; fi)
.  endfor
.endfor

.include <bsd.port.mk>
