--- chrome/browser/net/system_network_context_manager.cc.orig	2019-09-09 21:55:09 UTC
+++ chrome/browser/net/system_network_context_manager.cc
@@ -71,11 +71,11 @@
 #include "chrome/browser/chromeos/policy/browser_policy_connector_chromeos.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/common/chrome_paths_internal.h"
 #include "chrome/grit/chromium_strings.h"
 #include "ui/base/l10n/l10n_util.h"
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 namespace {
 
@@ -178,10 +178,10 @@ network::mojom::HttpAuthDynamicParamsPtr CreateHttpAut
   auth_dynamic_params->enable_negotiate_port =
       local_state->GetBoolean(prefs::kEnableAuthNegotiatePort);
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   auth_dynamic_params->delegate_by_kdc_policy =
       local_state->GetBoolean(prefs::kAuthNegotiateDelegateByKdcPolicy);
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   auth_dynamic_params->ntlm_v2_enabled =
@@ -412,10 +412,10 @@ SystemNetworkContextManager::SystemNetworkContextManag
   pref_change_registrar_.Add(prefs::kEnableAuthNegotiatePort,
                              auth_pref_callback);
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   pref_change_registrar_.Add(prefs::kAuthNegotiateDelegateByKdcPolicy,
                              auth_pref_callback);
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   pref_change_registrar_.Add(prefs::kNtlmV2Enabled, auth_pref_callback);
@@ -464,10 +464,10 @@ void SystemNetworkContextManager::RegisterPrefs(PrefRe
   registry->RegisterStringPref(prefs::kAuthServerWhitelist, std::string());
   registry->RegisterStringPref(prefs::kAuthNegotiateDelegateWhitelist,
                                std::string());
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kAuthNegotiateDelegateByKdcPolicy,
                                 false);
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   registry->RegisterBooleanPref(
@@ -562,7 +562,7 @@ void SystemNetworkContextManager::OnNetworkServiceCrea
   content::GetNetworkService()->ConfigureStubHostResolver(
       stub_resolver_enabled, std::move(dns_over_https_servers));
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
 
