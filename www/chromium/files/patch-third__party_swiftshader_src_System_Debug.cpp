--- third_party/swiftshader/src/System/Debug.cpp.orig	2021-12-31 01:00:55 UTC
+++ third_party/swiftshader/src/System/Debug.cpp
@@ -18,15 +18,19 @@
 #	include <android/log.h>
 #endif
 
-#if defined(__unix__)
+#if defined(__unix__) && !defined(__FreeBSD__)
 #	define PTRACE
 #	include <sys/ptrace.h>
 #	include <sys/types.h>
 #elif defined(_WIN32) || defined(_WIN64)
 #	include <windows.h>
-#elif defined(__APPLE__) || defined(__MACH__)
+#elif defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
+#	include <sys/types.h>
 #	include <sys/sysctl.h>
 #	include <unistd.h>
+#endif
+#if defined(__FreeBSD__)
+#	include <sys/user.h>
 #endif
 
 #include <atomic>
