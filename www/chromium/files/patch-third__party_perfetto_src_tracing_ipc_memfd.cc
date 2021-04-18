--- third_party/perfetto/src/tracing/ipc/memfd.cc.orig	2021-03-15 13:10:47 UTC
+++ third_party/perfetto/src/tracing/ipc/memfd.cc
@@ -18,9 +18,10 @@
 
 #include <errno.h>
 
-#define PERFETTO_MEMFD_ENABLED()             \
-  PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-      PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
+#define PERFETTO_MEMFD_ENABLED()               \
+  PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) ||   \
+      PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+      PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 #if PERFETTO_MEMFD_ENABLED()
 
