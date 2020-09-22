--- headless/lib/browser/headless_browser_main_parts.h.orig	2020-09-08 12:14:06.000000000 -0700
+++ headless/lib/browser/headless_browser_main_parts.h	2020-09-17 12:52:49.986542000 -0700
@@ -32,7 +32,7 @@
 #if defined(OS_MACOSX)
   void PreMainMessageLoopStart() override;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   void PostMainMessageLoopStart() override;
 #endif
   void QuitMainMessageLoop();
