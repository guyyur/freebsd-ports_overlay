--- src/if-bsd.c.orig	2018-06-21 14:35:46.000000000 +0300
+++ src/if-bsd.c	2018-07-12 22:27:08.525524000 +0300
@@ -832,7 +832,7 @@ if_address6(unsigned char cmd, const str
 	 */
 
 #if !((defined(__NetBSD_Version__) && __NetBSD_Version__ >= 799003600) || \
-      (defined(__OpenBSD__) && OpenBSD >= 201605))
+      (defined(__OpenBSD__) && OpenBSD >= 201605) || (defined(__FreeBSD__) && defined(RTF_CONNECTED)))
 	if (cmd == RTM_NEWADDR && !(ia->flags & IPV6_AF_ADDED)) {
 		ifa.ifra_lifetime.ia6t_vltime = ND6_INFINITE_LIFETIME;
 		ifa.ifra_lifetime.ia6t_pltime = ND6_INFINITE_LIFETIME;
@@ -1410,11 +1410,13 @@ if_setup_inet6(const struct interface *i
 	flags = (int)nd.ndi.flags;
 #endif
 
+#if 0
 #ifdef ND6_IFF_AUTO_LINKLOCAL
 	/* Unlike the kernel,
 	 * dhcpcd make make a stable private address. */
 	flags &= ~ND6_IFF_AUTO_LINKLOCAL;
 #endif
+#endif
 
 #ifdef ND6_IFF_PERFORMNUD
 	/* NUD is kind of essential. */
