--- chrome/browser/about_flags.cc.orig	2020-10-07 16:38:37 UTC
+++ chrome/browser/about_flags.cc
@@ -184,7 +184,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/native_theme/native_theme_features.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -872,7 +872,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
 };
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -1105,7 +1105,7 @@ const FeatureEntry::FeatureVariation
         }};
 
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
-        // defined(OS_WIN)
+        // defined(OS_WIN) || defined(OS_BSD)
 
 const FeatureEntry::FeatureParam kOmniboxOnFocusSuggestionsParamSERP[] = {
     {"ZeroSuggestVariant:6:*", "RemoteSendUrl"},
@@ -2767,13 +2767,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kForceEnableDevicesPageName,
      flag_descriptions::kForceEnableDevicesPageDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kForceEnableDevicesPage)},
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl2-compute-context",
      flag_descriptions::kWebGL2ComputeContextName,
      flag_descriptions::kWebGL2ComputeContextDescription,
      kOsWin | kOsLinux | kOsCrOS,
      SINGLE_VALUE_TYPE(switches::kEnableWebGL2ComputeContext)},
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-webgl-draft-extensions",
      flag_descriptions::kWebglDraftExtensionsName,
      flag_descriptions::kWebglDraftExtensionsDescription, kOsAll,
@@ -2958,7 +2958,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableOfflinePreviewsDescription, kOsAndroid,
      FEATURE_VALUE_TYPE(previews::features::kOfflinePreviews)},
 #endif  // OS_ANDROID
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -2968,7 +2968,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // OS_CHROMEOS || OS_LINUX
+#endif  // OS_CHROMEOS || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -3766,7 +3766,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -3826,7 +3826,7 @@ const FeatureEntry kFeatureEntries[] = {
          kOmniboxRichAutocompletionShowAdditionalTextVariations,
          "OmniboxBundledExperimentV1")},
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
-        // defined(OS_WIN)
+        // defined(OS_WIN) || defined(OS_BSD)
 
     {"enable-speculative-service-worker-start-on-query-input",
      flag_descriptions::kSpeculativeServiceWorkerStartOnQueryInputName,
@@ -4111,14 +4111,14 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
-        // defined(OS_CHROMEOS)
+        // defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"ntp-dismiss-promos", flag_descriptions::kNtpDismissPromosName,
@@ -4841,7 +4841,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(ENABLE_CLICK_TO_CALL)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD) 
     {"remote-copy-receiver", flag_descriptions::kRemoteCopyReceiverName,
      flag_descriptions::kRemoteCopyReceiverDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyReceiver)},
@@ -4858,7 +4858,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRemoteCopyProgressNotificationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyProgressNotification)},
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
-        // defined(OS_CHROMEOS)
+        // defined(OS_CHROMEOS) || defined(OS_BSD)
 
     {"restrict-gamepad-access", flag_descriptions::kRestrictGamepadAccessName,
      flag_descriptions::kRestrictGamepadAccessDescription, kOsAll,
@@ -4888,7 +4888,7 @@ const FeatureEntry kFeatureEntries[] = {
          send_tab_to_self::kSendTabToSelfOmniboxSendingAnimation)},
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"sharing-peer-connection-receiver",
      flag_descriptions::kSharingPeerConnectionReceiverName,
      flag_descriptions::kSharingPeerConnectionReceiverDescription, kOsDesktop,
@@ -4899,7 +4899,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingPeerConnectionSenderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kSharingPeerConnectionSender)},
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
-        // defined(OS_CHROMEOS)
+        // defined(OS_CHROMEOS) || defined(OS_BSD)
 
     {"sharing-prefer-vapid", flag_descriptions::kSharingPreferVapidName,
      flag_descriptions::kSharingPreferVapidDescription, kOsAll,
@@ -4974,13 +4974,13 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"enable-reopen-tab-in-product-help",
      flag_descriptions::kReopenTabInProductHelpName,
      flag_descriptions::kReopenTabInProductHelpDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feature_engagement::kIPHReopenTabFeature)},
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
-        // defined(OS_CHROMEOS)
+        // defined(OS_CHROMEOS) || defined(OS_BSD)
 
     {"enable-audio-focus-enforcement",
      flag_descriptions::kEnableAudioFocusEnforcementName,
@@ -5464,7 +5464,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
      kOsWin | kOsMac | kOsLinux,
@@ -5494,7 +5494,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsOverlayControls)},
 #endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
-        // defined(OS_CHROMEOS)
+        // defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
     {"win-use-native-spellchecker",
