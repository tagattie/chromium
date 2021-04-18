--- content/shell/renderer/web_test/test_runner.cc.orig	2020-10-07 16:38:45 UTC
+++ content/shell/renderer/web_test/test_runner.cc
@@ -80,7 +80,7 @@
 #include "ui/gfx/skia_util.h"
 #include "ui/gfx/test/icc_profiles.h"
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 #include "third_party/blink/public/platform/web_font_render_style.h"
 #endif
 
@@ -2230,7 +2230,7 @@ void TestRunner::Reset() {
   blink::WebTestingSupport::ResetRuntimeFeatures();
   blink::WebCache::Clear();
   blink::WebSecurityPolicy::ClearOriginAccessList();
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   blink::WebFontRenderStyle::SetSubpixelPositioning(false);
 #endif
   blink::ResetDomainRelaxationForTest();
@@ -2781,7 +2781,7 @@ void TestRunner::AddOriginAccessAllowListEntry(
 }
 
 void TestRunner::SetTextSubpixelPositioning(bool value) {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // Since FontConfig doesn't provide a variable to control subpixel
   // positioning, we'll fall back to setting it globally for all fonts.
   blink::WebFontRenderStyle::SetSubpixelPositioning(value);
