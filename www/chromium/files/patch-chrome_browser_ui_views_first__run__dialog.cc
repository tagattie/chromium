--- chrome/browser/ui/views/first_run_dialog.cc.orig	2021-12-07 05:33:21 UTC
+++ chrome/browser/ui/views/first_run_dialog.cc
@@ -38,7 +38,7 @@
 
 namespace {
 
-#if !defined(OS_MAC)
+#if !defined(OS_MAC) && !defined(OS_BSD)
 void InitCrashReporterIfEnabled(bool enabled) {
   if (!crash_reporter::IsCrashpadEnabled() && enabled)
     breakpad::InitCrashReporter(std::string());
@@ -126,7 +126,7 @@ bool FirstRunDialog::Accept() {
 
 #if defined(OS_MAC)
   ChangeMetricsReportingState(report_crashes_->GetChecked());
-#else
+#elif !defined(OS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   metrics::structured::NeutrinoDevicesLog(
       metrics::structured::NeutrinoDevicesLocation::kFirstRunDialog);
