
PORTNAME=	odroid-c1-boot-files
PORTVERSION=	2016.03
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
DIST_SUBDIR=	local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Boot files for Hardkernel ODROID C1

USES=		tar:bzip2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/bl1.bin.hardkernel \
		${DATADIR}/bl1-mbr.tmp \
		${DATADIR}/u-boot.bin \
		${DATADIR}/boot.ini

do-fetch:

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bl1.bin.hardkernel ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/bl1-mbr.tmp ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/u-boot.bin ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${FILESDIR}/boot.ini ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
