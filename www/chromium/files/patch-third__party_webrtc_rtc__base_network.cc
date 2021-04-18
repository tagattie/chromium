--- third_party/webrtc/rtc_base/network.cc.orig	2021-03-13 00:03:44 UTC
+++ third_party/webrtc/rtc_base/network.cc
@@ -244,7 +244,12 @@ AdapterType GetAdapterTypeFromName(const char* network
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::NetworkManager() {}
