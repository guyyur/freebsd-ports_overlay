* Call the devd config backend functions if activated
*
--- config/config.c.orig	2017-03-15 18:05:25 UTC
+++ config/config.c
@@ -55,6 +55,9 @@ config_init(void)
 #elif defined(CONFIG_WSCONS)
     if (!config_wscons_init())
         ErrorF("[config] failed to initialise wscons\n");
+#elif defined(CONFIG_DEVD)
+    if (!config_devd_init())
+        ErrorF("[config] failed to initialise devd\n");
 #endif
 }
 
@@ -67,6 +70,8 @@ config_fini(void)
     config_hal_fini();
 #elif defined(CONFIG_WSCONS)
     config_wscons_fini();
+#elif defined(CONFIG_DEVD)
+    config_devd_fini();
 #endif
 }
 
