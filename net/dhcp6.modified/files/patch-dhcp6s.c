--- dhcp6s.c.orig	2017-02-28 21:06:15.000000000 +0200
+++ dhcp6s.c	2017-04-11 16:42:48.061200000 +0300
@@ -527,7 +527,7 @@ server6_init()
 		    strerror(errno));
 		exit(1);
 	}
-#if !defined(__linux__) && !defined(__sun__)
+#if !defined(__linux__) && !defined(__sun__) && !defined(__FreeBSD__)
 	/* make the socket write-only */
 	if (shutdown(outsock, 0)) {
 		d_printf(LOG_ERR, FNAME, "shutdown(outbound, 0): %s",
