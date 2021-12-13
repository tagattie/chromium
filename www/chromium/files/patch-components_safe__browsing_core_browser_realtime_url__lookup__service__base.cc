--- components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2021-12-07 05:33:27 UTC
+++ components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -109,7 +109,7 @@ RTLookupRequest::OSType GetRTLookupRequestOSType() {
   return RTLookupRequest::OS_TYPE_FUCHSIA;
 #elif defined(OS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif defined(OS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;
