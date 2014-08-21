--- ./base/test/expectations/expectation.cc.orig	2014-08-20 21:02:41.000000000 +0200
+++ ./base/test/expectations/expectation.cc	2014-08-21 23:18:10.000000000 +0200
@@ -60,6 +60,7 @@
         variant != "64") {
       return false;
     }
+  } else if (name == "FreeBSD") {
   } else if (name == "ChromeOS") {
     // TODO(rsesek): Figure out what ChromeOS needs.
   } else if (name == "iOS") {
@@ -125,6 +126,8 @@
     platform.variant = "32";
   else if (arch == "x86_64")
     platform.variant = "64";
+#elif defined(OS_FREEBSD)
+  platform.name = "FreeBSD";
 #else
   NOTREACHED();
 #endif
