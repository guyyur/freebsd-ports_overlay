PORTNAME=	dtb
PORTVERSION=	4.10
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
MASTER_SITES=	https://cdn.kernel.org/pub/linux/kernel/v4.x/
DISTNAME=	linux-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Device Tree Blobs (DTBs)

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/dtc:sysutils/dtc

ARCHS=		arm

DTS_FILES.arm=	am335x-boneblack.dts \
		bcm2835-rpi-b.dts \
		meson8b-odroidc1.dts \
		sun4i-a10-cubieboard.dts \
		sun8i-h3-orangepi-one.dts \
		sun8i-h3-orangepi-pc.dts

.for ARCH in ${ARCHS}
EXTRACT_AFTER_ARGS+= ${DISTNAME}/arch/${ARCH}/boot/dts
.endfor
EXTRACT_AFTER_ARGS+= ${DISTNAME}/include

NO_ARCH=	yes

USES=		tar:xz

PATCH_STRIP=	-p1

do-build:
.for ARCH in ${ARCHS}
.for DTS_FILE in ${DTS_FILES.${ARCH}}
	cpp -P -x assembler-with-cpp -I ${WRKSRC}/arch/${ARCH}/boot/dts -I ${WRKSRC}/include ${WRKSRC}/arch/${ARCH}/boot/dts/${DTS_FILE} | \
	    ${LOCALBASE}/bin/dtc -O dtb -o ${WRKSRC}/arch/${ARCH}/boot/dts/${DTS_FILE:S/.dts/.dtb/} -b 0 -p 1024 -i ${WRKSRC}/arch/${ARCH}/boot/dts -i ${WRKSRC}/include
.endfor
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for ARCH in ${ARCHS}
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
.for DTS_FILE in ${DTS_FILES.${ARCH}}
	${INSTALL_DATA} ${WRKSRC}/arch/${ARCH}/boot/dts/${DTS_FILE:S/.dts/.dtb/} \
	    ${STAGEDIR}${DATADIR}/${ARCH}/
.endfor
.endfor

.include <bsd.port.mk>
