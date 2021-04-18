--- weblayer/browser/content_browser_client_impl.cc.orig	2020-10-07 16:39:11 UTC
+++ weblayer/browser/content_browser_client_impl.cc
@@ -129,7 +129,7 @@
 #include "weblayer/browser/tts_environment_android_impl.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "content/public/common/content_descriptors.h"
 #endif
 
@@ -375,7 +375,7 @@ void ContentBrowserClientImpl::ConfigureNetworkContext
 
 void ContentBrowserClientImpl::OnNetworkServiceCreated(
     network::mojom::NetworkService* network_service) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   network::mojom::CryptConfigPtr config = network::mojom::CryptConfig::New();
   content::GetNetworkService()->SetCryptConfig(std::move(config));
 #endif
@@ -801,7 +801,7 @@ SafeBrowsingService* ContentBrowserClientImpl::GetSafe
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 void ContentBrowserClientImpl::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -835,7 +835,7 @@ void ContentBrowserClientImpl::GetAdditionalMappedFile
     mappings->Share(service_manager::kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_LINUX) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 
 void ContentBrowserClientImpl::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
