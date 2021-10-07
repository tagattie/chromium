--- ui/gfx/x/gen_xproto.py.orig	2021-10-01 01:37:23.000000000 +0000
+++ ui/gfx/x/gen_xproto.py	2021-10-07 18:24:11.923085000 +0000
@@ -1219,6 +1219,8 @@
         self.write('#include <cstring>')
         self.write('#include <vector>')
         self.write()
+        self.write('#include <unistd.h>')
+        self.write()
         self.write('#include "base/component_export.h"')
         self.write('#include "base/memory/ref_counted_memory.h"')
         self.write('#include "base/memory/scoped_refptr.h"')
@@ -1313,6 +1315,7 @@
         self.write()
         self.write('#include <xcb/xcb.h>')
         self.write('#include <xcb/xcbext.h>')
+        self.write('#include <unistd.h>')
         self.write()
         self.write('#include "base/logging.h"')
         self.write('#include "base/posix/eintr_wrapper.h"')
