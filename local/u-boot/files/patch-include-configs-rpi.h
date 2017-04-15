diff -uNdrp include/configs/rpi.h include/configs/rpi.h
--- include/configs/rpi.h	2017-01-09 18:57:05.000000000 +0200
+++ include/configs/rpi.h	2017-02-04 19:55:21.942432000 +0200
@@ -184,6 +184,8 @@
 	"scriptaddr=0x02000000\0" \
 	"ramdisk_addr_r=0x02100000\0" \
 
+#define NO_LOAD_FDT
+
 #define BOOT_TARGET_DEVICES(func) \
 	func(MMC, mmc, 0) \
 	func(USB, usb, 0) \
