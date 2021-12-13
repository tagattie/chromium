--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-12-07 05:33:15 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -28,10 +28,14 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 #endif
 
+#if defined(OS_BSD)
+#include <fcntl.h>
+#endif
+
 #include "base/allocator/partition_allocator/page_allocator.h"
 
 #ifndef MAP_ANONYMOUS
@@ -151,12 +155,19 @@ void* SystemAllocPagesInternal(void* hint,
   PA_DCHECK(PageTag::kFirst <= page_tag);
   PA_DCHECK(PageTag::kLast >= page_tag);
   int fd = VM_MAKE_TAG(static_cast<int>(page_tag));
+#elif defined(OS_FREEBSD)
+  int fd = HANDLE_EINTR(open("/dev/zero", O_RDWR | O_CLOEXEC));
+  PA_PCHECK(fd != -1);
 #else
   int fd = -1;
 #endif
 
   int access_flag = GetAccessFlags(accessibility);
+#if defined(OS_FREEBSD)
+  int map_flags = MAP_PRIVATE;
+#else
   int map_flags = MAP_ANONYMOUS | MAP_PRIVATE;
+#endif
 
 #if defined(OS_MAC)
   // On macOS 10.14 and higher, executables that are code signed with the
@@ -183,6 +194,8 @@ void* SystemAllocPagesInternal(void* hint,
     prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME, ret, length,
           PageTagToName(page_tag));
   }
+#elif defined(OS_FREEBSD)
+  HANDLE_EINTR(close(fd));
 #endif
 
   return ret;
@@ -291,9 +304,19 @@ void DecommitAndZeroSystemPagesInternal(void* address,
   // shall be removed, as if by an appropriate call to munmap(), before the
   // new mapping is established." As a consequence, the memory will be
   // zero-initialized on next access.
+#if !defined(OS_FREEBSD)
   void* ptr = mmap(address, length, PROT_NONE,
                    MAP_FIXED | MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
   PA_CHECK(ptr == address);
+#else
+  int fd = HANDLE_EINTR(open("/dev/zero", O_RDONLY));
+  PA_CHECK(fd != -1);
+
+  void *ptr = mmap(address, length, PROT_NONE,
+                   MAP_FIXED | MAP_PRIVATE, fd, 0);
+  PA_PCHECK(ptr == address);
+  HANDLE_EINTR(close(fd));
+#endif
 }
 
 void RecommitSystemPagesInternal(
@@ -346,6 +369,8 @@ void DiscardSystemPagesInternal(void* address, size_t 
     ret = madvise(address, length, MADV_DONTNEED);
   }
   PA_PCHECK(ret == 0);
+#elif defined(OS_FREEBSD)
+  PA_PCHECK(0 == madvise(address, length, MADV_FREE));
 #else
   // We have experimented with other flags, but with suboptimal results.
   //
