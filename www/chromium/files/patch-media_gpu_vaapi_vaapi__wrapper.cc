--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2021-12-16 15:13:01 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -559,7 +559,7 @@ VADisplayState::VADisplayState()
 bool VADisplayState::Initialize() {
   base::AutoLock auto_lock(va_lock_);
 
-#if defined(USE_OZONE) && defined(OS_LINUX)
+#if defined(USE_OZONE) && (defined(OS_LINUX) || defined(OS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
