--- services/service_manager/sandbox/switches.cc.orig	2020-09-08 12:14:09.000000000 -0700
+++ services/service_manager/sandbox/switches.cc	2020-09-17 12:18:17.445443000 -0700
@@ -85,7 +85,7 @@
 // Meant to be used as a browser-level switch for testing purposes only.
 const char kNoSandbox[] = "no-sandbox";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Instructs the zygote to launch without a sandbox. Processes forked from this
 // type of zygote will apply their own custom sandboxes later.
 const char kNoZygoteSandbox[] = "no-zygote-sandbox";
