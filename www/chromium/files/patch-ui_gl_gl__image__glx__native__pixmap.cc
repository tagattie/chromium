--- ui/gl/gl_image_glx_native_pixmap.cc	2021-10-08 12:59:35.530370000 +0000
+++ ui/gl/gl_image_glx_native_pixmap.cc.orig	2021-10-08 12:59:28.659514000 +0000
@@ -4,8 +4,6 @@
 
 #include "ui/gl/gl_image_glx_native_pixmap.h"
 
-#include <unistd.h>
-
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/buffer_types.h"
 #include "ui/gfx/linux/native_pixmap_dmabuf.h"
