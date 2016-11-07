--- if-bsd.c.orig	2016-10-07 11:05:10.000000000 +0300
+++ if-bsd.c	2016-10-07 14:56:08.791234000 +0300
@@ -976,6 +976,7 @@ if_address6(unsigned char cmd, const str
 	 * Fixed in OpenBSD-5.9
 	 */
 
+#if 0
 #if !((defined(__NetBSD_Version__) && __NetBSD_Version__ >= 799003600) || \
       (defined(__OpenBSD__)))
 	if (cmd == RTM_NEWADDR && !(ia->flags & IPV6_AF_ADDED)) {
@@ -984,6 +985,7 @@ if_address6(unsigned char cmd, const str
 		(void)ioctl(priv->pf_inet6_fd, SIOCAIFADDR_IN6, &ifa);
 	}
 #endif
+#endif
 
 #if defined(__OpenBSD__)
 	/* BUT OpenBSD does not reset the address lifetime
