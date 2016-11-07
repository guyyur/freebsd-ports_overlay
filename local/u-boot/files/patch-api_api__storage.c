--- api/api_storage.c.orig	2016-05-16 17:40:32.000000000 +0300
+++ api/api_storage.c	2016-07-20 02:23:24.064647000 +0300
@@ -153,7 +153,8 @@ static int dev_stor_get(int type, int fi
 			dd = (struct blk_desc *)di->cookie;
 			if (dd->type == DEV_TYPE_UNKNOWN) {
 				debugf("device instance exists, but is not active..");
-				found = 0;
+				di->di_stor.block_count = 0;
+				di->di_stor.block_size = 0;
 			} else {
 				di->di_stor.block_count = dd->lba;
 				di->di_stor.block_size = dd->blksz;
