--- ui/gfx/x/gen_xproto.py.orig	2021-10-05 16:55:56 UTC
+++ ui/gfx/x/gen_xproto.py
@@ -1313,6 +1313,7 @@ class GenXproto(FileWriter):
         self.write()
         self.write('#include <xcb/xcb.h>')
         self.write('#include <xcb/xcbext.h>')
+        self.write('#include <unistd.h>')
         self.write()
         self.write('#include "base/logging.h"')
         self.write('#include "base/posix/eintr_wrapper.h"')
