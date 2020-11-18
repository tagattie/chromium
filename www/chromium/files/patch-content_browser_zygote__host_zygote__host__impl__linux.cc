--- content/browser/zygote_host/zygote_host_impl_linux.cc.orig	2020-11-18 15:42:24 UTC
+++ content/browser/zygote_host/zygote_host_impl_linux.cc
@@ -216,7 +216,7 @@ pid_t ZygoteHostImpl::LaunchZygote(
   return pid;
 }
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
 void ZygoteHostImpl::AdjustRendererOOMScore(base::ProcessHandle pid,
                                             int score) {
   // 1) You can't change the oom_score_adj of a non-dumpable process
