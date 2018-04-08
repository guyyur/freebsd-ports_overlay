--- src/if-bsd.c.orig	2018-03-27 08:45:24.000000000 +0300
+++ src/if-bsd.c	2018-03-31 15:57:15.237502000 +0300
@@ -834,6 +834,7 @@ if_address6(unsigned char cmd, const str
 	 * Fixed in OpenBSD-5.9
 	 */
 
+#if 0
 #if !((defined(__NetBSD_Version__) && __NetBSD_Version__ >= 799003600) || \
       (defined(__OpenBSD__) && OpenBSD >= 201605))
 	if (cmd == RTM_NEWADDR && !(ia->flags & IPV6_AF_ADDED)) {
@@ -842,6 +843,7 @@ if_address6(unsigned char cmd, const str
 		(void)ioctl(priv->pf_inet6_fd, SIOCAIFADDR_IN6, &ifa);
 	}
 #endif
+#endif
 
 #if defined(__OpenBSD__) && OpenBSD <= 201705
 	/* BUT OpenBSD older than 6.2 does not reset the address lifetime
@@ -1413,11 +1415,13 @@ if_setup_inet6(const struct interface *i
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
@@ -1478,6 +1482,7 @@ if_setup_inet6(const struct interface *i
 	}
 #endif
 
+#if 0
 #if defined(IPV6CTL_ACCEPT_RTADV) || defined(ND6_IFF_ACCEPT_RTADV)
 	/* Flush the kernel knowledge of advertised routers
 	 * and prefixes so the kernel does not expire prefixes
@@ -1494,5 +1499,6 @@ if_setup_inet6(const struct interface *i
 			logwarn("SIOCSPFXFLUSH_IN6");
 	}
 #endif
+#endif
 }
 #endif
