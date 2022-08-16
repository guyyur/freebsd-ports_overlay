
PORTNAME=	sbl-hebrew
PORTVERSION=	1.56.a.016
CATEGORIES=	x11-fonts
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
DISTFILES=	SBL_Hbrw.ttf
EXTRACT_ONLY=

MAINTAINER=	guy
COMMENT=	Society of Biblical Literature’s Hebrew font

# LICENSE=	SBL

USES=		fonts

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DISTFILES:S|^|${FONTSDIR}/|}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in ${DISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${i} ${STAGEDIR}${FONTSDIR}/
.endfor

.include <bsd.port.mk>
