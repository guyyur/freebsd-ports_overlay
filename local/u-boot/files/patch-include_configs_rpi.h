--- include/configs/rpi.h.orig	2016-05-16 17:40:32.000000000 +0300
+++ include/configs/rpi.h	2016-07-16 23:53:22.185719000 +0300
@@ -215,4 +215,29 @@
 
 #define CONFIG_BOOTDELAY 2
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+#define CONFIG_API
+#define CONFIG_EFI_PARTITION
+
+#define CONFIG_SYS_MMC_MAX_DEVICE 1
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	ENV_MEM_LAYOUT_SETTINGS \
+	"stdin=serial,lcd\0" \
+	"stderr=serial,lcd\0" \
+	"stdout=serial,lcd\0" \
+	"boot_targets=mmc0\0" \
+	"bootcmd_mmc0=setenv devtype mmc; setenv devnum 0; run ubldr_boot\0" \
+	"ubldr_boot=load ${devtype} ${devnum}:1 ${kernel_addr_r} ubldr.bin && env set loaderdev ${devtype} ${devnum} && go ${kernel_addr_r}\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"for target in ${boot_targets}; do run bootcmd_${target}; done"
+
+#define CONFIG_CMD_CACHE
+
 #endif
