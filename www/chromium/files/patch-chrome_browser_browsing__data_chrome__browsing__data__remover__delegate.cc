--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2021-12-07 05:33:19 UTC
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -608,7 +608,9 @@ void ChromeBrowsingDataRemoverDelegate::RemoveEmbedder
     }
 #endif
 
+#if !defined(OS_BSD)
     CreateCrashUploadList()->Clear(delete_begin_, delete_end_);
+#endif
 
     FindBarStateFactory::GetForBrowserContext(profile_)->SetLastSearchText(
         std::u16string());
