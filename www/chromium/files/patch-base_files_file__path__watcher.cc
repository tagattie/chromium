--- base/files/file_path_watcher.cc.orig	2020-10-07 16:38:34 UTC
+++ base/files/file_path_watcher.cc
@@ -19,11 +19,11 @@ FilePathWatcher::~FilePathWatcher() {
 
 // static
 bool FilePathWatcher::RecursiveWatchAvailable() {
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_BSD)) || \
     defined(OS_ANDROID) || defined(OS_AIX)
   return true;
 #else
-  // FSEvents isn't available on iOS.
+  // FSEvents isn't available on iOS and the kqueue watcher.
   return false;
 #endif
 }
