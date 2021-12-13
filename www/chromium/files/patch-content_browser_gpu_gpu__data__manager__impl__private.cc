--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2021-12-07 05:33:28 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1308,7 +1308,7 @@ void GpuDataManagerImplPrivate::AppendGpuCommandLine(
       break;
     case gpu::GpuMode::SWIFTSHADER: {
       bool legacy_software_gl = true;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
       // This setting makes WebGL run on SwANGLE instead of SwiftShader GL.
       legacy_software_gl = false;
 #endif
