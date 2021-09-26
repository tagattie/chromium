--- third_party/libsync/src/sync.c.orig	2021-09-25 13:08:42 UTC
+++ third_party/libsync/src/sync.c
@@ -29,6 +29,9 @@
 
 #include <sync/sync.h>
 
+#if defined(__FreeBSD__)
+#define ETIME ETIMEDOUT
+#endif
 
 struct sw_sync_create_fence_data {
   __u32 value;
