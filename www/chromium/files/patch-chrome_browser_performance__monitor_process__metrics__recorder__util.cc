--- chrome/browser/performance_monitor/process_metrics_recorder_util.cc.orig	2021-12-07 05:33:20 UTC
+++ chrome/browser/performance_monitor/process_metrics_recorder_util.cc
@@ -41,7 +41,7 @@ void RecordProcessHistograms(const char* histogram_suf
                        ""),
       metrics.cpu_usage * kCPUUsageFactor, kCPUUsageHistogramMin,
       kCPUUsageHistogramMax, kCPUUsageHistogramBucketCount);
-#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_AIX)
   base::UmaHistogramCounts10000(
       base::JoinString({"PerformanceMonitor.IdleWakeups.", histogram_suffix},
