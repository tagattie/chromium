--- chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc.orig	2021-09-24 18:35:34 UTC
+++ chrome/browser/ui/webui/settings/settings_localized_strings_provider.cc
@@ -112,7 +112,7 @@
 #include "ui/accessibility/accessibility_features.h"
 #endif
 
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #include "ui/display/screen.h"
 #endif
 
@@ -390,7 +390,7 @@ void AddAppearanceStrings(content::WebUIDataSource* ht
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
 #if defined(USE_OZONE)
   const bool show_custom_chrome_frame =
       features::IsUsingOzonePlatform() &&
