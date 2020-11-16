--- third_party/perfetto/src/base/unix_socket.cc.orig	2020-11-13 06:42:20 UTC
+++ third_party/perfetto/src/base/unix_socket.cc
@@ -625,7 +625,7 @@ void UnixSocket::ReadPeerCredentials() {
   if (sock_raw_.family() != SockFamily::kUnix)
     return;
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   struct ucred user_cred;
   socklen_t len = sizeof(user_cred);
