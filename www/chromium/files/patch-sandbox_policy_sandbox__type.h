--- sandbox/policy/sandbox_type.h.orig	2021-12-07 05:33:34 UTC
+++ sandbox/policy/sandbox_type.h
@@ -110,7 +110,7 @@ enum class SandboxType {
   kZygoteIntermediateSandbox,
 #endif
 
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // Equivalent to no sandbox on all non-Fuchsia platforms.
   // Minimally privileged sandbox on Fuchsia.
   kVideoCapture,
@@ -143,7 +143,7 @@ inline constexpr sandbox::policy::SandboxType MapToSan
     case sandbox::mojom::Sandbox::kPrintBackend:
       return sandbox::policy::SandboxType::kPrintBackend;
 #endif
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case sandbox::mojom::Sandbox::kVideoCapture:
       return sandbox::policy::SandboxType::kVideoCapture;
 #endif
