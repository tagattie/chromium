--- content/browser/browser_main_loop.cc.orig	2020-09-08 19:14:05 UTC
+++ content/browser/browser_main_loop.cc
@@ -610,7 +610,7 @@
   }
 #endif  // !defined(OS_MACOSX)
 
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   // We use quite a few file descriptors for our IPC as well as disk the disk
   // cache,and the default limit on the Mac is low (256), so bump it up.
@@ -620,7 +620,7 @@
   // users can easily hit this limit with many open tabs. Bump up the limit to
   // an arbitrarily high number. See https://crbug.com/539567
   base::IncreaseFdLimitTo(8192);
-#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) ||
         // defined(OS_ANDROID)
 
 #if defined(OS_WIN)
