--- ui/gfx/native_pixmap_handle.cc.orig	2020-11-13 06:37:06 UTC
+++ ui/gfx/native_pixmap_handle.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <drm_fourcc.h>
 #include "base/posix/eintr_wrapper.h"
 #endif
@@ -21,7 +21,7 @@
 
 namespace gfx {
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 static_assert(NativePixmapHandle::kNoModifier == DRM_FORMAT_MOD_INVALID,
               "gfx::NativePixmapHandle::kNoModifier should be an alias for"
               "DRM_FORMAT_MOD_INVALID");
@@ -32,7 +32,7 @@ NativePixmapPlane::NativePixmapPlane() : stride(0), of
 NativePixmapPlane::NativePixmapPlane(int stride,
                                      int offset,
                                      uint64_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                      ,
                                      base::ScopedFD fd
 #elif defined(OS_FUCHSIA)
@@ -43,7 +43,7 @@ NativePixmapPlane::NativePixmapPlane(int stride,
     : stride(stride),
       offset(offset),
       size(size)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       ,
       fd(std::move(fd))
 #elif defined(OS_FUCHSIA)
@@ -71,7 +71,7 @@ NativePixmapHandle& NativePixmapHandle::operator=(Nati
 NativePixmapHandle CloneHandleForIPC(const NativePixmapHandle& handle) {
   NativePixmapHandle clone;
   for (auto& plane : handle.planes) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     DCHECK(plane.fd.is_valid());
     base::ScopedFD fd_dup(HANDLE_EINTR(dup(plane.fd.get())));
     if (!fd_dup.is_valid()) {
@@ -97,7 +97,7 @@ NativePixmapHandle CloneHandleForIPC(const NativePixma
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   clone.modifier = handle.modifier;
 #endif
 
