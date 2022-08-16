PORTNAME=	sunxi-tools
PORTVERSION=	1.4.2.20201020
# DISTVERSIONPREFIX=	v
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME_SANITIZED}_GH${_GITHUB_REV}
CATEGORIES=	comms

WRKSRC=		${WRKDIR}/sunxi-tools-${GH_TAGNAME_SANITIZED}

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Tools to help hacking Allwinner devices

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gmake pkgconfig
USE_GITHUB=	nodefault
GH_ACCOUNT=	linux-sunxi
GH_TAGNAME=	14ff3e3

.include <bsd.port.mk>
