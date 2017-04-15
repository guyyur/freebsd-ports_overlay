PORTNAME=	u-boot
PORTVERSION=	2017.03
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Cross-build das u-boot for multiple boards

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:devel/arm-none-eabi-gcc \
		gsed:textproc/gsed \
		python:lang/python \
		swig3.0:devel/swig30 \
		${LOCALBASE}/bin/dtc:sysutils/dtc
USES=		tar:bz2 gmake python:build shebangfix

SHEBANG_FILES=	tools/binman/binman.py
SSP_UNSAFE=	yes

MAKE_ARGS+=	V=1

NO_ARCH=	yes

UBOOT_ARCHS?=	arm

UBOOT_BOARDS.arm?=	\
			am335x_boneblack \
			Cubieboard \
			orangepi_one \
			orangepi_pc \
			rpi

UBOOT_FILES.am335x_boneblack?=	MLO u-boot.img
UBOOT_FILES.Cubieboard?=	u-boot-sunxi-with-spl.bin
UBOOT_FILES.orangepi_one?=	u-boot-sunxi-with-spl.bin
UBOOT_FILES.orangepi_pc?=	u-boot-sunxi-with-spl.bin
UBOOT_FILES.rpi?=		u-boot.bin

do-configure:
.for UBOOT_ARCH in ${UBOOT_ARCHS}
.  for UBOOT_BOARD in ${UBOOT_BOARDS.${UBOOT_ARCH}}
	(cd ${WRKSRC} && mkdir -p build/${UBOOT_BOARD} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_CMD} O="build/${UBOOT_BOARD}" ${UBOOT_BOARD}_defconfig)
.  endfor
.endfor

do-build:
.for UBOOT_ARCH in ${UBOOT_ARCHS}
.  for UBOOT_BOARD in ${UBOOT_BOARDS.${UBOOT_ARCH}}
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS:C,^${DESTDIRNAME}=.*,,g} ARCH=${UBOOT_ARCH} CROSS_COMPILE=${UBOOT_ARCH}-none-eabi- O="build/${UBOOT_BOARD}" ${ALL_TARGET})
.  endfor
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for UBOOT_ARCH in ${UBOOT_ARCHS}
.  for UBOOT_BOARD in ${UBOOT_BOARDS.${UBOOT_ARCH}}
	${MKDIR} ${STAGEDIR}${DATADIR}/${UBOOT_BOARD}
.    for F in ${UBOOT_FILES.${UBOOT_BOARD}}
	(cd ${WRKSRC}/build/${UBOOT_BOARD}; ${INSTALL_DATA} ${F} ${STAGEDIR}${DATADIR}/${UBOOT_BOARD}/)
.    endfor
.  endfor
.endfor

.include <bsd.port.mk>
