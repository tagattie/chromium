--- v8/src/base/platform/platform-freebsd.cc.orig	2021-03-13 00:03:47 UTC
+++ v8/src/base/platform/platform-freebsd.cc
@@ -82,8 +82,8 @@ std::vector<OS::SharedLibraryAddress> OS::GetSharedLib
             lib_name = std::string(path);
           }
           result.push_back(SharedLibraryAddress(
-              lib_name, reinterpret_cast<uintptr_t>(map->kve_start),
-              reinterpret_cast<uintptr_t>(map->kve_end)));
+              lib_name, static_cast<uintptr_t>(map->kve_start),
+              static_cast<uintptr_t>(map->kve_end)));
         }
 
         start += ssize;
