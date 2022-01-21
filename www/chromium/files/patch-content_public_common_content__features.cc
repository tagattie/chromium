--- content/public/common/content_features.cc.orig	2021-12-31 00:57:32 UTC
+++ content/public/common/content_features.cc
@@ -51,7 +51,7 @@ const base::Feature kAudioServiceOutOfProcess {
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
       base::FEATURE_ENABLED_BY_DEFAULT
 #else
       base::FEATURE_DISABLED_BY_DEFAULT
@@ -920,13 +920,13 @@ const base::Feature kWebAssemblyBaseline{"WebAssemblyB
 const base::Feature kWebAssemblyCodeProtection{
     "WebAssemblyCodeProtection", base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(ARCH_CPU_X86_64)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(ARCH_CPU_X86_64)
 // Use memory protection keys in userspace (PKU) (if available) to protect code
 // JITed for WebAssembly. Fall back to traditional memory protection if
 // WebAssemblyCodeProtection is also enabled.
 const base::Feature kWebAssemblyCodeProtectionPku{
     "WebAssemblyCodeProtectionPku", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS)) &&
+#endif  // (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) &&
         // defined(ARCH_CPU_X86_64)
 
 // Enable WebAssembly lazy compilation (JIT on first call).
@@ -945,7 +945,7 @@ const base::Feature kWebAssemblyTiering{"WebAssemblyTi
 // Enable WebAssembly trap handler.
 const base::Feature kWebAssemblyTrapHandler {
   "WebAssemblyTrapHandler",
-#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || \
+#if ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD) || \
       defined(OS_MAC)) &&                                             \
      defined(ARCH_CPU_X86_64)) ||                                     \
     (defined(OS_MAC) && defined(ARCH_CPU_ARM64))
@@ -973,7 +973,7 @@ const base::Feature kWebAuthCable {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 // If updating this, also update kWebAuthCableServerLink.
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_LINUX) || defined(OS_BSD)
       base::FEATURE_DISABLED_BY_DEFAULT
 #else
       base::FEATURE_ENABLED_BY_DEFAULT
@@ -1132,7 +1132,7 @@ const base::Feature kRetryGetVideoCaptureDeviceInfos{
 
 #endif  // defined(OS_MAC)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // If the JavaScript on a WebUI page has an error (such as an unhandled
 // exception), report that error back the crash reporting infrastructure, same
 // as we do for program crashes.
