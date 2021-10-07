--- ui/gfx/x/generated_protos/dri3.cc.orig	2021-10-07 19:45:55.090508000 +0000
+++ ui/gfx/x/generated_protos/dri3.cc	2021-10-07 19:46:10.788422000 +0000
@@ -43,6 +43,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/xproto_internal.h"
