
PORTNAME=	sunxi-tools-spi
PORTVERSION=	1.4.2.32d8535
# DISTVERSIONPREFIX=	v
CATEGORIES=	comms
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME_SANITIZED}

WRKSRC=		${WRKDIR}/sunxi-tools-${GH_TAGNAME_SANITIZED}

MAINTAINER=	guy
COMMENT=	Tools to help hacking Allwinner devices (with SPI patches)

LICENSE=	GPLv2+

BROKEN_mips=		fails to build: unrecognized command line option "-Wno-unused-result"
BROKEN_mips64=		fails to build: unrecognized command line option "-Wno-unused-result"
BROKEN_powerpc64=	fails to build: unrecognized command line option "-Wno-unused-result"

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ssvb
GH_PROJECT=	sunxi-tools
GH_TAGNAME=	32d8535

.include <bsd.port.mk>
