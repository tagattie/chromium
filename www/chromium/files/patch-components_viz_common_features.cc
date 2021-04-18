--- components/viz/common/features.cc.orig	2020-10-07 16:38:44 UTC
+++ components/viz/common/features.cc
@@ -21,7 +21,7 @@ const base::Feature kForcePreferredIntervalForVideo{
     "ForcePreferredIntervalForVideo", base::FEATURE_DISABLED_BY_DEFAULT};
 
 // Use the SkiaRenderer.
-#if defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))
+#if (defined(OS_LINUX) && !(defined(OS_CHROMEOS) || BUILDFLAG(IS_CHROMECAST))) || defined(OS_BSD)
 const base::Feature kUseSkiaRenderer{"UseSkiaRenderer",
                                      base::FEATURE_ENABLED_BY_DEFAULT};
 #else
