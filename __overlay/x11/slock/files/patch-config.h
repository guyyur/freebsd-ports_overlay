--- /dev/null	2017-03-06 21:29:25.000000000 +0200
+++ config.h	2017-03-06 21:30:46.520236000 +0200
@@ -0,0 +1,12 @@
+/* user and group to drop privileges to */
+static const char *user  = "nobody";
+static const char *group = "nogroup";
+
+static const char *colorname[NUMCOLS] = {
+	[INIT] =   "#404040",   /* after initialization */
+	[INPUT] =  "#005577",   /* during input */
+	[FAILED] = "#CC3333",   /* wrong password */
+};
+
+/* treat a cleared input like a wrong password (color) */
+static const int failonclear = 1;
