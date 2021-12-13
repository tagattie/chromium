--- chrome/browser/web_applications/web_app_provider.cc.orig	2021-12-07 05:33:22 UTC
+++ chrome/browser/web_applications/web_app_provider.cc
@@ -261,7 +261,7 @@ void WebAppProvider::CreateSubsystems(Profile* profile
 
     std::unique_ptr<UrlHandlerManager> url_handler_manager;
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
     url_handler_manager = std::make_unique<UrlHandlerManagerImpl>(profile);
 #endif
 
