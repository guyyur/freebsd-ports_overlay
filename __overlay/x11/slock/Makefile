PORTNAME=	slock
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Simple X screen locker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe xorg
CPE_VENDOR=	suckless
USE_XORG=	x11 xext xorgproto xrandr xt
MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}" \
		MANPREFIX="${MANPREFIX}/man"

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H|-DHAVE_PAM|' -e '/^LDFLAGS/s|$$| -lpam|' \
		${WRKSRC}/config.mk

.include <bsd.port.mk>
