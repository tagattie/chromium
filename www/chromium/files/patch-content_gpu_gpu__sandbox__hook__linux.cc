--- content/gpu/gpu_sandbox_hook_linux.cc.orig	2020-11-13 06:36:43 UTC
+++ content/gpu/gpu_sandbox_hook_linux.cc
@@ -359,8 +359,10 @@ std::vector<BrokerFilePermission> FilePermissionsForGp
   AddStandardGpuPermissions(&permissions);
   return permissions;
 }
+#endif
 
 void LoadArmGpuLibraries() {
+#if !defined(OS_BSD)
   // Preload the Mali library.
   if (UseChromecastSandboxAllowlist()) {
     for (const char* path : kAllowedChromecastPaths) {
@@ -375,6 +377,7 @@ void LoadArmGpuLibraries() {
     // Preload the Tegra V4L2 (video decode acceleration) library.
     dlopen(kLibTegraPath, dlopen_flag);
   }
+#endif
 }
 
 bool LoadAmdGpuLibraries() {
@@ -441,6 +444,7 @@ bool LoadLibrariesForGpu(
   return true;
 }
 
+#if !defined(OS_BSD)
 sandbox::syscall_broker::BrokerCommandSet CommandSetForGPU(
     const sandbox::policy::SandboxLinux::Options& options) {
   sandbox::syscall_broker::BrokerCommandSet command_set;
