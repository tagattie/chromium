--- content/public/common/content_constants.h.orig	2020-10-07 16:38:45 UTC
+++ content/public/common/content_constants.h
@@ -70,7 +70,7 @@ CONTENT_EXPORT extern const char kCorsExemptPurposeHea
 // it at run time.
 CONTENT_EXPORT std::string GetCorsExemptRequestedWithHeaderName();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // The OOM score adj constants
 // The highest and lowest assigned OOM score adjustment (oom_score_adj) for
 // renderers and extensions used by the OomPriority Manager.
