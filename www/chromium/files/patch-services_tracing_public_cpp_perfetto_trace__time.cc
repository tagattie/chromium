--- services/tracing/public/cpp/perfetto/trace_time.cc.orig	2021-06-11 09:59:26 UTC
+++ services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,7 +12,7 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_BSD) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
     defined(OS_FUCHSIA)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
@@ -22,4 +22,4 @@ int64_t TraceBootTicksNow() {
   return TRACE_TIME_TICKS_NOW().since_origin().InNanoseconds();
 }
 
-}  // namespace tracing
+}  // namespace tracing
\ No newline at end of file
