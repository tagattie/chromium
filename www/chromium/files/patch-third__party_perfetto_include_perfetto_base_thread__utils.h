--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2021-12-07 05:36:50 UTC
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -37,6 +37,9 @@ __declspec(dllimport) unsigned long __stdcall GetCurre
 #else
 #include <pthread.h>
 #endif
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#include <pthread_np.h>
+#endif
 
 namespace perfetto {
 namespace base {
@@ -45,6 +48,11 @@ namespace base {
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
+}
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+using PlatformThreadId = pid_t;
+inline PlatformThreadId GetThreadId() {
+  return pthread_getthreadid_np();
 }
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;
