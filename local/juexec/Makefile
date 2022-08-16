
PORTNAME=	juexec
PORTVERSION=	1.1
CATEGORIES=	sysutils
PKGORIGIN=	local/${PORTDIRNAME}    # workaround for no local category
DISTFILES=	# none
NO_WRKSUBDIR=	yes

MAINTAINER=	guy
COMMENT=	a script to enter a jail as the running user

NO_BUILD=	yes
PLIST_FILES=	bin/juexec

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/juexec.sh ${STAGEDIR}${PREFIX}/bin/juexec

.include <bsd.port.mk>
