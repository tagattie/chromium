--- components/autofill/core/common/autofill_util.cc.orig	2021-05-12 22:05:49 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -171,7 +171,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return true;
 #else
