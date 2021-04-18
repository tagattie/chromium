--- base/security_unittest.cc.orig	2020-10-07 16:38:34 UTC
+++ base/security_unittest.cc
@@ -61,7 +61,7 @@ NOINLINE Type HideValueFromCompiler(volatile Type valu
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_APPLE)
+    defined(OS_APPLE) || defined(OS_BSD)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
