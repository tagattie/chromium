--- sandbox/policy/sandbox_type.cc.orig	2021-12-07 05:33:34 UTC
+++ sandbox/policy/sandbox_type.cc
@@ -34,7 +34,7 @@ bool IsUnsandboxedSandboxType(SandboxType sandbox_type
 #endif
     case SandboxType::kAudio:
       return false;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case SandboxType::kVideoCapture:
       return false;
 #endif
@@ -120,7 +120,7 @@ void SetCommandLineFlagsForSandboxType(base::CommandLi
 #endif
     case SandboxType::kPrintCompositor:
     case SandboxType::kAudio:
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case SandboxType::kVideoCapture:
 #endif
 #if defined(OS_WIN)
@@ -248,7 +248,7 @@ std::string StringFromUtilitySandboxType(SandboxType s
       return switches::kUtilitySandbox;
     case SandboxType::kAudio:
       return switches::kAudioSandbox;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
     case SandboxType::kVideoCapture:
       return switches::kVideoCaptureSandbox;
 #endif
@@ -350,7 +350,7 @@ SandboxType UtilitySandboxTypeFromString(const std::st
     return SandboxType::kAudio;
   if (sandbox_string == switches::kSpeechRecognitionSandbox)
     return SandboxType::kSpeechRecognition;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   if (sandbox_string == switches::kVideoCaptureSandbox)
     return SandboxType::kVideoCapture;
 #endif
