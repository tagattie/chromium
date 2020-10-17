--- chrome/app/chrome_main.cc.orig	2020-10-07 16:38:35 UTC
+++ chrome/app/chrome_main.cc
@@ -109,12 +109,12 @@ int ChromeMain(int argc, const char** argv) {
 
   // Chrome-specific process modes.
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   if (command_line->HasSwitch(switches::kHeadless)) {
     return headless::HeadlessShellMain(params);
   }
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
-        // defined(OS_WIN)
+        // defined(OS_WIN) || defined(OS_BSD)
 
   int rv = content::ContentMain(params);
 
