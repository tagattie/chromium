--- ./net/base/address_tracker_linux.h.orig	2014-06-30 21:02:51.000000000 +0200
+++ ./net/base/address_tracker_linux.h	2014-07-08 21:32:48.000000000 +0200
@@ -6,10 +6,12 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
+#if !defined(__FreeBSD__)
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
 #define net net_kernel
 #include <linux/rtnetlink.h>
 #undef net
+#endif
 
 #include <map>
 
