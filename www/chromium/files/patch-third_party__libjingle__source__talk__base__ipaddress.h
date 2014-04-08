--- ./third_party/libjingle/source/talk/base/ipaddress.h.orig	2014-04-02 21:06:30.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/ipaddress.h	2014-04-04 01:39:19.000000000 +0200
@@ -34,6 +34,9 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 #endif
+#ifdef BSD
+#include <sys/socket.h>
+#endif
 #ifdef WIN32
 #include <winsock2.h>
 #include <ws2tcpip.h>
