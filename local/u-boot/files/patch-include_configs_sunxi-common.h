--- include/configs/sunxi-common.h.orig	2016-05-16 17:40:32.000000000 +0300
+++ include/configs/sunxi-common.h	2016-07-16 23:59:09.585576000 +0300
@@ -513,4 +513,51 @@ extern int soft_i2c_gpio_scl;
 #define CONFIG_EXTRA_ENV_SETTINGS
 #endif
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+/* Add the API and ELF features needed for ubldr. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_API
+#endif
+
+/* Turn off dcache. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_SYS_DCACHE_OFF
+#define CONFIG_CMD_CACHE
+#endif
+
+/* Save the env to the fat partition. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#undef  CONFIG_ENV_IS_IN_MMC
+#undef  CONFIG_ENV_IS_IN_SPI_FLASH
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define CONFIG_SYS_MMC_MAX_DEVICE	4
+#define FAT_ENV_INTERFACE		"mmc"
+#define FAT_ENV_DEVICE_AND_PART		"0:1"
+#define FAT_ENV_FILE			"u-boot.env"
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	MEM_LAYOUT_ENV_SETTINGS \
+	CONSOLE_STDOUT_SETTINGS \
+	"stdin=serial,usbkbd\0" \
+	"fdtfile=" CONFIG_DEFAULT_DEVICE_TREE ".dtb\0" \
+	"console=ttyS0,115200\0" \
+	"boot_targets=mmc0 usb0\0" \
+	"bootcmd_mmc0=setenv devtype mmc; setenv devnum 0; run ubldr_boot\0" \
+	"bootcmd_usb0=setenv devtype usb; setenv devnum 0; usb start; run ubldr_boot\0" \
+	"ubldr_boot=load ${devtype} ${devnum}:1 ${fdt_addr_r} ${fdtfile} && load ${devtype} ${devnum}:1 ${kernel_addr_r} ubldr.bin && env set loaderdev ${devtype} ${devnum} && go ${kernel_addr_r}\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"for target in ${boot_targets}; do run bootcmd_${target}; done"
+#endif
+
 #endif /* _SUNXI_COMMON_CONFIG_H */
