diff --git a/include/portable_endian.h b/include/portable_endian.h
index 2b43378..f6b70f0 100644
--- include/portable_endian.h
+++ include/portable_endian.h
@@ -41,11 +41,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 
 #	include <sys/endian.h>
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__NetBSD__) || defined(__DragonFly__)
 
 #	include <sys/endian.h>
 
