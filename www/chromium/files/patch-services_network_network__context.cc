--- services/network/network_context.cc.orig	2021-12-07 05:33:34 UTC
+++ services/network/network_context.cc
@@ -2487,7 +2487,7 @@ NetworkContext::MakeSessionCleanupCookieStore() const 
 
   net::CookieCryptoDelegate* crypto_delegate = nullptr;
   if (params_->enable_encrypted_cookies) {
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && \
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && \
     !BUILDFLAG(IS_CHROMECAST)
     DCHECK(network_service_->os_crypt_config_set())
         << "NetworkService::SetCryptConfig must be called before creating a "
