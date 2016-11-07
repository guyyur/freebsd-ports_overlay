--- include/configs/am335x_evm.h.orig	2016-05-16 17:40:32.000000000 +0300
+++ include/configs/am335x_evm.h	2016-07-17 00:00:34.522319000 +0300
@@ -473,4 +473,57 @@
 #endif
 #endif  /* NOR support */
 
+/*****************************************************************************
+ * FreeBSD customizations from here down.
+ ****************************************************************************/
+
+/* Add the API and ELF features needed for ubldr. */
+#ifndef CONFIG_SPL_BUILD
+#define CONFIG_API
+#define CONFIG_SYS_MMC_MAX_DEVICE 2
+#ifndef CONFIG_SYS_DCACHE_OFF
+#define CONFIG_CMD_CACHE
+#endif
+#endif
+
+/* Save the env to the fat partition. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_ENV_IS_NOWHERE
+#undef  CONFIG_ENV_IS_IN_NAND
+#undef  CONFIG_ENV_IS_IN_MMC
+#define CONFIG_ENV_IS_IN_FAT
+#define CONFIG_FAT_WRITE
+#define FAT_ENV_INTERFACE		"mmc"
+#define FAT_ENV_DEVICE_AND_PART		"0"
+#define FAT_ENV_FILE			"u-boot.env"
+#endif
+
+/* Create a small(ish) boot environment for FreeBSD. */
+#ifndef CONFIG_SPL_BUILD
+#undef  CONFIG_EXTRA_ENV_SETTINGS
+#define CONFIG_EXTRA_ENV_SETTINGS \
+	DEFAULT_LINUX_BOOT_ENV \
+	"fdtfile=undefined\0" \
+	"findfdt=" \
+		"if test $board_name = A335BONE; then " \
+			"setenv fdtfile am335x-bone.dtb; fi; " \
+		"if test $board_name = A335BNLT; then " \
+			"setenv fdtfile am335x-boneblack.dtb; fi; " \
+		"if test $board_name = BBG1; then " \
+			"setenv fdtfile am335x-bonegreen.dtb; fi; " \
+		"if test $board_name = A33515BB; then " \
+			"setenv fdtfile am335x-evm.dtb; fi; " \
+		"if test $board_name = A335X_SK; then " \
+			"setenv fdtfile am335x-evmsk.dtb; fi; " \
+		"if test $fdtfile = undefined; then " \
+			"echo WARNING: Could not determine device tree to use; fi; \0" \
+	"boot_targets=mmc0 mmc1\0" \
+	"bootcmd_mmc0=setenv devtype mmc; setenv devnum 0; run ubldr_boot\0" \
+	"bootcmd_mmc1=setenv devtype mmc; setenv devnum 1; run ubldr_boot\0" \
+	"ubldr_boot=load ${devtype} ${devnum}:1 ${fdt_addr_r} ${fdtfile} && load ${devtype} ${devnum}:1 ${kernel_addr_r} ubldr.bin && env set loaderdev ${devtype} ${devnum} && go ${kernel_addr_r}\0"
+
+#undef  CONFIG_BOOTCOMMAND
+#define CONFIG_BOOTCOMMAND	"run findfdt; for target in ${boot_targets}; do run bootcmd_${target}; done"
+#endif
+
 #endif	/* ! __CONFIG_AM335X_EVM_H */
