--- content/browser/utility_sandbox_delegate.cc.orig	2021-12-07 05:33:28 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -57,7 +57,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_PLUGINS)
       sandbox_type_ == sandbox::policy::SandboxType::kPpapi ||
 #endif
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
       sandbox_type_ == sandbox::policy::SandboxType::kVideoCapture ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS_ASH)
