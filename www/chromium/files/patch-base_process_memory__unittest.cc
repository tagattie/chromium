--- base/process/memory_unittest.cc.orig	2020-10-07 16:38:34 UTC
+++ base/process/memory_unittest.cc
@@ -104,9 +104,9 @@ TEST(MemoryTest, AllocatorShimWorking) {
 #endif
 }
 
-// OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
+// BSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
-#if !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
+#if !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
 namespace {
@@ -631,5 +631,5 @@ TEST_F(OutOfMemoryHandledTest, UncheckedCalloc) {
 
 #endif  // BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) || defined(OS_ANDROID)
 
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
