--- ui/base/ime/fake_text_input_client.cc.orig	2021-12-07 05:34:23 UTC
+++ ui/base/ime/fake_text_input_client.cc
@@ -160,7 +160,7 @@ bool FakeTextInputClient::ShouldDoLearning() {
   return false;
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 bool FakeTextInputClient::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
