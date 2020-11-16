--- net/socket/udp_socket_posix.cc.orig	2020-11-13 06:36:46 UTC
+++ net/socket/udp_socket_posix.cc
@@ -917,7 +917,11 @@ int UDPSocketPosix::SetMulticastOptions() {
         mreq.imr_ifindex = multicast_interface_;
         mreq.imr_address.s_addr = htonl(INADDR_ANY);
         int rv = setsockopt(socket_, IPPROTO_IP, IP_MULTICAST_IF,
+#if defined(OS_BSD)
+                            reinterpret_cast<const char*>(&mreq.imr_interface.s_addr), sizeof(mreq.imr_interface.s_addr));
+#else
                             reinterpret_cast<const char*>(&mreq), sizeof(mreq));
+#endif
         if (rv)
           return MapSystemError(errno);
         break;
@@ -1018,9 +1022,18 @@ int UDPSocketPosix::LeaveGroup(const IPAddress& group_
     case IPAddress::kIPv4AddressSize: {
       if (addr_family_ != AF_INET)
         return ERR_ADDRESS_INVALID;
+#if defined(OS_BSD)
+      ip_mreq mreq = {};
+      int error = GetIPv4AddressFromIndex(socket_, multicast_interface_,
+                                          &mreq.imr_interface.s_addr);
+
+      if (error != OK)
+        return error;
+#else
       ip_mreqn mreq = {};
       mreq.imr_ifindex = multicast_interface_;
       mreq.imr_address.s_addr = INADDR_ANY;
+#endif
       memcpy(&mreq.imr_multiaddr, group_address.bytes().data(),
              IPAddress::kIPv4AddressSize);
       int rv = setsockopt(socket_, IPPROTO_IP, IP_DROP_MEMBERSHIP,
