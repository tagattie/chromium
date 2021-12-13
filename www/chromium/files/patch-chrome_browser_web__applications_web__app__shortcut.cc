--- chrome/browser/web_applications/web_app_shortcut.cc.orig	2021-12-07 05:33:22 UTC
+++ chrome/browser/web_applications/web_app_shortcut.cc
@@ -39,7 +39,7 @@ namespace {
 
 #if defined(OS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
@@ -109,7 +109,7 @@ ScopedShortcutOverrideForTesting::~ScopedShortcutOverr
   directories = {&desktop, &application_menu, &quick_launch, &startup};
 #elif defined(OS_MAC)
   directories = {&chrome_apps_folder};
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   directories = {&desktop};
 #endif
   for (base::ScopedTempDir* dir : directories) {
@@ -150,7 +150,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
         scoped_override->chrome_apps_folder.CreateUniqueTempDirUnderPath(
             base_path);
     DCHECK(success);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     bool success =
         scoped_override->desktop.CreateUniqueTempDirUnderPath(base_path);
     DCHECK(success);
@@ -168,7 +168,7 @@ std::unique_ptr<ScopedShortcutOverrideForTesting> Over
 #elif defined(OS_MAC)
     bool success = scoped_override->chrome_apps_folder.CreateUniqueTempDir();
     DCHECK(success);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
     bool success = scoped_override->desktop.CreateUniqueTempDir();
     DCHECK(success);
 #endif
