--- components/metrics/system_memory_stats_recorder_linux.cc.orig	2020-10-07 16:38:42 UTC
+++ components/metrics/system_memory_stats_recorder_linux.cc
@@ -31,6 +31,7 @@ namespace metrics {
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_FREEBSD)
   base::SystemMemoryInfoKB memory;
   if (!base::GetSystemMemoryInfo(&memory))
     return;
@@ -83,6 +84,7 @@ void RecordMemoryStats(RecordMemoryStatsType type) {
       break;
     }
   }
+#endif // !defined(OS_FREEBSD)
 }
 
 }  // namespace metrics
