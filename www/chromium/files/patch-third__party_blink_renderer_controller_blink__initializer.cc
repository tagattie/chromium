--- third_party/blink/renderer/controller/blink_initializer.cc.orig	2021-12-31 00:57:40 UTC
+++ third_party/blink/renderer/controller/blink_initializer.cc
@@ -71,11 +71,11 @@
 #include "third_party/blink/renderer/controller/oom_intervention_impl.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "third_party/blink/renderer/controller/memory_usage_monitor_posix.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_MAC) || defined(OS_WIN)
 #include "third_party/blink/renderer/controller/highest_pmf_reporter.h"
 #include "third_party/blink/renderer/controller/user_level_memory_pressure_signal_generator.h"
@@ -155,7 +155,7 @@ void InitializeCommon(Platform* platform, mojo::Binder
   CrashMemoryMetricsReporterImpl::Instance();
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_MAC) || defined(OS_WIN)
   // Initialize UserLevelMemoryPressureSignalGenerator so it starts monitoring.
   if (UserLevelMemoryPressureSignalGenerator::Enabled())
@@ -227,7 +227,7 @@ void BlinkInitializer::RegisterInterfaces(mojo::Binder
               main_thread->GetTaskRunner());
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   binders.Add(ConvertToBaseRepeatingCallback(
                   CrossThreadBindRepeating(&MemoryUsageMonitorPosix::Bind)),
               main_thread->GetTaskRunner());
