
PORTNAME=	raspberrypi-firmware-boot
PORTVERSION=	1.20160620
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
DIST_SUBDIR=	local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boot files for Raspberry Pi

USES=		tar:xz
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/LICENCE.broadcom \
		${DATADIR}/bootcode.bin \
		${DATADIR}/fixup.dat \
		${DATADIR}/fixup_cd.dat \
		${DATADIR}/fixup_db.dat \
		${DATADIR}/fixup_x.dat \
		${DATADIR}/start.elf \
		${DATADIR}/start_cd.elf \
		${DATADIR}/start_db.elf \
		${DATADIR}/start_x.elf \
		${DATADIR}/config.txt

do-fetch:

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${FILESDIR}/config.txt ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
