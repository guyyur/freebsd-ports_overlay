PORTNAME=	tint2
DISTVERSIONPREFIX=	v
DISTVERSION=	17.0.2
CATEGORIES=	x11

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libImlib2.so:graphics/imlib2 \
		libstartup-notification-1.so:x11/startup-notification

USES=		alias cmake desktop-file-utils gettext-runtime gnome pkgconfig \
		shared-mime-info xorg
USE_GNOME=	cairo glib20 gtk30 librsvg2 pango
USE_XORG=	x11 xcomposite xdamage xext xfixes xinerama xrandr xrender

CMAKE_ARGS=	-DMANDIR:PATH=man \
		-DSYSCONFDIR:PATH=etc

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Gettext

USE_GITLAB=	yes
GL_ACCOUNT=	o9000
GL_COMMIT=	f8f9c18cef88239688c62fdba70db9b082e1f0f4

.include <bsd.port.mk>
