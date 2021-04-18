--- base/cpu.cc.orig	2020-10-07 16:38:34 UTC
+++ base/cpu.cc
@@ -29,7 +29,7 @@
 #include "base/threading/thread_restrictions.h"
 #endif
 
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
 #include "base/files/file_util.h"
 #endif
 
@@ -150,7 +150,7 @@ uint64_t xgetbv(uint32_t xcr) {
 
 #endif  // ARCH_CPU_X86_FAMILY
 
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
 std::string* CpuInfoBrand() {
   static std::string* brand = []() {
     // This function finds the value from /proc/cpuinfo under the key "model
@@ -180,7 +180,7 @@ std::string* CpuInfoBrand() {
   return brand;
 }
 #endif  // defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) ||
-        // defined(OS_LINUX))
+        // defined(OS_LINUX) || defined(OS_BSD))
 
 }  // namespace
 
@@ -302,7 +302,7 @@ void CPU::Initialize() {
     }
   }
 #elif defined(ARCH_CPU_ARM_FAMILY)
-#if (defined(OS_ANDROID) || defined(OS_LINUX))
+#if (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   cpu_brand_ = *CpuInfoBrand();
 #elif defined(OS_WIN)
   // Windows makes high-resolution thread timing information available in
