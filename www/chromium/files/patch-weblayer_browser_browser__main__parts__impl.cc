--- weblayer/browser/browser_main_parts_impl.cc.orig	2020-10-07 16:39:11 UTC
+++ weblayer/browser/browser_main_parts_impl.cc
@@ -60,7 +60,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -148,7 +148,7 @@ int BrowserMainPartsImpl::PreEarlyInitialization() {
   if (!features::IsUsingOzonePlatform())
     ui::SetDefaultX11ErrorHandlers();
 #endif
-#if defined(USE_AURA) && defined(OS_LINUX)
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
