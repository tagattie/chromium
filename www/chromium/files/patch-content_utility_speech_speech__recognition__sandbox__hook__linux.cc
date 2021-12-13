--- content/utility/speech/speech_recognition_sandbox_hook_linux.cc.orig	2021-12-07 05:33:29 UTC
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.cc
@@ -11,11 +11,14 @@
 #include "sandbox/linux/syscall_broker/broker_command.h"
 #include "sandbox/linux/syscall_broker/broker_file_permission.h"
 
+#if !defined(OS_BSD)
 using sandbox::syscall_broker::BrokerFilePermission;
 using sandbox::syscall_broker::MakeBrokerCommandSet;
+#endif
 
 namespace speech {
 
+#if !defined(OS_BSD)
 namespace {
 
 // Gets the file permissions required by the Speech On-Device API (SODA).
@@ -49,9 +52,11 @@ std::vector<BrokerFilePermission> GetSodaFilePermissio
 }
 
 }  // namespace
+#endif
 
 bool SpeechRecognitionPreSandboxHook(
     sandbox::policy::SandboxLinux::Options options) {
+#if !defined(OS_BSD)
 #if BUILDFLAG(ENABLE_SODA)
   void* soda_test_library = dlopen(GetSodaTestBinaryPath().value().c_str(),
                                    RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE);
@@ -73,6 +78,7 @@ bool SpeechRecognitionPreSandboxHook(
                                sandbox::policy::SandboxLinux::PreSandboxHook(),
                                options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }
