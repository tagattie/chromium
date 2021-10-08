--- ui/gfx/x/generated_protos/shm.cc.orig	2021-10-07 21:05:15.105639000 +0000
+++ ui/gfx/x/generated_protos/shm.cc	2021-10-07 21:05:22.216516000 +0000
@@ -43,6 +43,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
