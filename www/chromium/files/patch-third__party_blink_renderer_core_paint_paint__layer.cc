--- third_party/blink/renderer/core/paint/paint_layer.cc.orig	2021-12-07 05:33:36 UTC
+++ third_party/blink/renderer/core/paint/paint_layer.cc
@@ -112,7 +112,7 @@ namespace {
 static CompositingQueryMode g_compositing_query_mode =
     kCompositingQueriesAreOnlyAllowedInCertainDocumentLifecyclePhases;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 struct SameSizeAsPaintLayer : GarbageCollected<PaintLayer>, DisplayItemClient {
   // The bit fields may fit into the machine word of DisplayItemClient which
   // has only 8-bit data.
