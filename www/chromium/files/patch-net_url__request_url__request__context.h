--- net/url_request/url_request_context.h.orig	2021-12-07 05:33:33 UTC
+++ net/url_request/url_request_context.h
@@ -80,7 +80,7 @@ class NET_EXPORT URLRequestContext {
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if !defined(OS_WIN) && !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !defined(OS_WIN) && !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
