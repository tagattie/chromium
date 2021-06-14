--- services/tracing/public/cpp/perfetto/trace_time.cc.orig	2021-06-14 12:19:41 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,7 +12,7 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_BSD) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
     defined(OS_FUCHSIA)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
