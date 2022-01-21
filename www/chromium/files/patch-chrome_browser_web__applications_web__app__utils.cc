--- chrome/browser/web_applications/web_app_utils.cc.orig	2021-12-31 00:57:25 UTC
+++ chrome/browser/web_applications/web_app_utils.cc
@@ -236,13 +236,13 @@ std::u16string GetFileTypeAssociationsHandledByWebApps
   const apps::FileHandlers file_handlers =
       GetFileHandlersForAllWebAppsWithOrigin(profile, url);
   std::vector<std::string> associations;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   std::set<std::string> mime_types_set =
       apps::GetMimeTypesFromFileHandlers(file_handlers);
   associations.reserve(mime_types_set.size());
   associations.insert(associations.end(), mime_types_set.begin(),
                       mime_types_set.end());
-#else   // !defined(OS_LINUX)
+#else   // !defined(OS_LINUX) || defined(OS_BSD)
   std::set<std::string> extensions_set =
       apps::GetFileExtensionsFromFileHandlers(file_handlers);
   associations.reserve(extensions_set.size());
@@ -253,7 +253,7 @@ std::u16string GetFileTypeAssociationsHandledByWebApps
                  [](const std::string& extension) {
                    return base::ToUpperASCII(extension.substr(1));
                  });
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (found_multiple)
     *found_multiple = associations.size() > 1;
