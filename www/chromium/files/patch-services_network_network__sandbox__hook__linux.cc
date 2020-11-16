--- services/network/network_sandbox_hook_linux.cc.orig	2020-11-13 06:36:46 UTC
+++ services/network/network_sandbox_hook_linux.cc
@@ -32,6 +32,7 @@ bool NetworkPreSandboxHook(sandbox::policy::SandboxLin
       sandbox::policy::SandboxLinux::PreSandboxHook(), options);
 
   instance->EngageNamespaceSandboxIfPossible();
+#endif // defined(OS_BSD)
   return true;
 }
 
