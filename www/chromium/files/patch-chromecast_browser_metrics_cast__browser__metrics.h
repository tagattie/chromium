--- chromecast/browser/metrics/cast_browser_metrics.h.orig	2021-12-07 05:33:24 UTC
+++ chromecast/browser/metrics/cast_browser_metrics.h
@@ -42,10 +42,10 @@ class CastBrowserMetrics {
  private:
   std::unique_ptr<CastMetricsServiceClient> metrics_service_client_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ExternalMetrics* external_metrics_ = nullptr;
   ExternalMetrics* platform_metrics_ = nullptr;
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 };
 
 }  // namespace metrics
