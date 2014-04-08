--- ./third_party/libjingle/source/talk/base/systeminfo.cc.orig	2014-04-02 21:06:30.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/systeminfo.cc	2014-04-04 01:39:19.000000000 +0200
@@ -36,7 +36,7 @@
 #elif defined(OSX)
 #include <ApplicationServices/ApplicationServices.h>
 #include <CoreServices/CoreServices.h>
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include <unistd.h>
 #endif
 #if defined(OSX) || defined(IOS)
@@ -48,7 +48,7 @@
 #include "talk/base/win32.h"
 #elif defined(OSX)
 #include "talk/base/macconversion.h"
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 #endif
 #include "talk/base/common.h"
