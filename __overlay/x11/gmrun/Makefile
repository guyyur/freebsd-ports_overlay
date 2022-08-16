PORTNAME=	gmrun
PORTVERSION=	1.4w
CATEGORIES=	x11
MASTER_SITES=	GH

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Customizable program to run programs, with tab-completion

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpopt.so:devel/popt

USES=		compiler:c++11-lang gmake gnome localbase:ldflags pkgconfig

USE_GNOME=	cairo gtk30
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	WdesktopX

OPTIONS_DEFINE= NLS
OPTIONS_SUB=    yes

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/gmrunrc ${STAGEDIR}${PREFIX}/etc/gmrunrc.sample

.include <bsd.port.mk>
