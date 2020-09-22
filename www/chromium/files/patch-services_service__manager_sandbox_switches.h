--- services/service_manager/sandbox/switches.h.orig	2020-09-08 12:14:09.000000000 -0700
+++ services/service_manager/sandbox/switches.h	2020-09-17 12:18:07.447224000 -0700
@@ -55,7 +55,7 @@
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxAllowSysVShm[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kGpuSandboxFailuresFatal[];
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoSandbox[];
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 SERVICE_MANAGER_SANDBOX_EXPORT extern const char kNoZygoteSandbox[];
 #endif
 #if defined(OS_WIN)
