--- src/if-bsd.c.orig	2020-06-04 15:35:46.000000000 +0300
+++ src/if-bsd.c	2020-06-10 18:46:41.176171000 +0300
@@ -1042,7 +1042,7 @@ if_address6(unsigned char cmd, const struct ipv6_addr 
 	 */
 
 #if !((defined(__NetBSD_Version__) && __NetBSD_Version__ >= 799003600) || \
-      (defined(__OpenBSD__) && OpenBSD >= 201605))
+      (defined(__OpenBSD__) && OpenBSD >= 201605) || defined(__FreeBSD__))
 	if (cmd == RTM_NEWADDR && !(ia->flags & IPV6_AF_ADDED)) {
 		ifa.ifra_lifetime.ia6t_vltime = ND6_INFINITE_LIFETIME;
 		ifa.ifra_lifetime.ia6t_pltime = ND6_INFINITE_LIFETIME;
@@ -1784,9 +1784,11 @@ if_setup_inet6(const struct interface *ifp)
 	flags = (int)nd.ndi.flags;
 #endif
 
+#if 0
 #ifdef ND6_IFF_AUTO_LINKLOCAL
 	/* Unlike the kernel, dhcpcd make make a stable private address. */
 	flags &= ~ND6_IFF_AUTO_LINKLOCAL;
+#endif
 #endif
 
 #ifdef ND6_IFF_PERFORMNUD
