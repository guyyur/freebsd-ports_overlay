# Created by: Roy Marples <roy@marples.name>
# $FreeBSD: head/net/dhcpcd/Makefile 453875M $

PORTNAME=	dhcpcd
PORTVERSION=	7.0.3
CATEGORIES=	net
MASTER_SITES=	http://roy.marples.name/downloads/dhcpcd/ \
		ftp://roy.marples.name/pub/dhcpcd/\
		http://roy.aydogan.net/dhcpcd/ \
		http://cflags.cc/roy/dhcpcd/ \
		LOCAL/delphij

MAINTAINER=	roy@marples.name
COMMENT=	DHCP/IPv4LL/IPv6RS/DHCPv6 client

LICENSE=	BSD2CLAUSE

USES=		cpe tar:xz
CPE_VENDOR=	dhcpcd_project
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/examples
USE_RC_SUBR=	dhcpcd

PLIST_SUB+=	YPBIND="@comment "

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/dhcpcd.conf \
		${STAGEDIR}${PREFIX}/etc/dhcpcd.conf.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcpcd

.include <bsd.port.mk>
