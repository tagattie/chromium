--- content/public/common/content_constants.cc.orig	2020-10-07 16:38:45 UTC
+++ content/public/common/content_constants.cc
@@ -56,7 +56,7 @@ std::string GetCorsExemptRequestedWithHeaderName() {
   return base::JoinString(pieces, "-");
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int kLowestRendererOomScore = 300;
 const int kHighestRendererOomScore = 1000;
 
