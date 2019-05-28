--- base/allocator/allocator_shim.cc.orig	2019-04-30 22:22:27 UTC
+++ base/allocator/allocator_shim.cc
@@ -69,7 +69,7 @@ inline const base::allocator::AllocatorDispatch* GetCh
   // Unfortunately due to that bug NoBarrier_Load() is mistakenly fully
   // barriered on Linux+Clang, and that causes visible perf regressons.
   return reinterpret_cast<const base::allocator::AllocatorDispatch*>(
-#if defined(OS_LINUX) && defined(__clang__)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(__clang__)
       *static_cast<const volatile base::subtle::AtomicWord*>(&g_chain_head)
 #else
       base::subtle::NoBarrier_Load(&g_chain_head)
