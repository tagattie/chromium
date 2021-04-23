--- components/security_interstitials/content/captive_portal_blocking_page.cc.orig	2021-04-14 18:41:00 UTC
+++ components/security_interstitials/content/captive_portal_blocking_page.cc
@@ -106,7 +106,7 @@ std::string CaptivePortalBlockingPage::GetWiFiSSID() c
   wifi_service->GetConnectedNetworkSSID(&ssid, &error);
   if (!error.empty())
     return std::string();
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ssid = net::GetWifiSSID();
 #elif defined(OS_ANDROID)
   ssid = net::android::GetWifiSSID();
