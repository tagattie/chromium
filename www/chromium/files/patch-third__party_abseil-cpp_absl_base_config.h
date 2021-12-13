--- third_party/abseil-cpp/absl/base/config.h.orig	2021-12-07 05:33:34 UTC
+++ third_party/abseil-cpp/absl/base/config.h
@@ -216,7 +216,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // against libstdc++ with _GLIBCXX_HAVE_TLS defined.
 #ifdef ABSL_HAVE_TLS
 #error ABSL_HAVE_TLS cannot be directly set
-#elif defined(__linux__) && (defined(__clang__) || defined(_GLIBCXX_HAVE_TLS))
+#elif (defined(__linux__) || defined(__OpenBSD__) || defined(__FreeBSD__))  && (defined(__clang__) || defined(_GLIBCXX_HAVE_TLS))
 #define ABSL_HAVE_TLS 1
 #endif
 
@@ -413,7 +413,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||    \
     defined(__asmjs__) || defined(__wasm__) || defined(__Fuchsia__) ||    \
-    defined(__sun) || defined(__ASYLO__) || defined(__myriad2__)
+    defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||       \
+    defined(__OpenBSD__)
 #define ABSL_HAVE_MMAP 1
 #endif
 
@@ -424,7 +425,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(_AIX) || defined(__ros__)
+    defined(_AIX) || defined(__ros__) || defined(__OpenBSD__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
 
@@ -443,7 +444,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // POSIX.1-2001.
 #ifdef ABSL_HAVE_SCHED_YIELD
 #error ABSL_HAVE_SCHED_YIELD cannot be directly set
-#elif defined(__linux__) || defined(__ros__) || defined(__native_client__)
+#elif defined(__linux__) || defined(__ros__) || defined(__native_client__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SCHED_YIELD 1
 #endif
 
@@ -458,7 +459,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // platforms.
 #ifdef ABSL_HAVE_SEMAPHORE_H
 #error ABSL_HAVE_SEMAPHORE_H cannot be directly set
-#elif defined(__linux__) || defined(__ros__)
+#elif defined(__linux__) || defined(__ros__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SEMAPHORE_H 1
 #endif
 
