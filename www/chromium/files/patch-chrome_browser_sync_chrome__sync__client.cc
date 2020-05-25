--- chrome/browser/sync/chrome_sync_client.cc.orig	2020-05-13 18:40:22 UTC
+++ chrome/browser/sync/chrome_sync_client.cc
@@ -445,7 +445,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
   }
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // Dictionary sync is enabled by default.
   if (!disabled_types.Has(syncer::DICTIONARY)) {
     controllers.push_back(
@@ -453,7 +453,7 @@ ChromeSyncClient::CreateDataTypeControllers(syncer::Sy
             syncer::DICTIONARY, model_type_store_factory,
             GetSyncableServiceForType(syncer::DICTIONARY), dump_stack));
   }
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
   if (arc::IsArcAllowedForProfile(profile_) &&
