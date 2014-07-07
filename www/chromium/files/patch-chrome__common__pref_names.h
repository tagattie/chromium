--- ./chrome/common/pref_names.h.orig	2014-06-30 21:02:11.000000000 +0200
+++ ./chrome/common/pref_names.h	2014-07-07 15:12:47.000000000 +0200
@@ -298,7 +298,7 @@
 extern const char kForceSafeSearch[];
 extern const char kDeleteTimePeriod[];
 extern const char kLastClearBrowsingDataTime[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
