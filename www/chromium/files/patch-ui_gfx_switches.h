--- ui/gfx/switches.h.orig	2021-12-31 00:58:32 UTC
+++ ui/gfx/switches.h
@@ -17,7 +17,7 @@ GFX_SWITCHES_EXPORT extern const char kEnableNativeGpu
 GFX_SWITCHES_EXPORT extern const char kForcePrefersReducedMotion[];
 GFX_SWITCHES_EXPORT extern const char kHeadless[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 GFX_SWITCHES_EXPORT extern const char kX11Display[];
 GFX_SWITCHES_EXPORT extern const char kNoXshm[];
 #endif
