--- third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp.orig	2021-05-12 22:13:44 UTC
+++ third_party/pdfium/xfa/fxfa/parser/cxfa_timezoneprovider.cpp
@@ -12,6 +12,9 @@
 #include "build/build_config.h"
 
 static bool g_bProviderTimeZoneSet = false;
+#if defined(OS_BSD)
+static long g_lTimeZoneOffset = 0;
+#endif
 
 #if defined(OS_WIN)
 #define TIMEZONE _timezone
@@ -24,9 +27,21 @@ static bool g_bProviderTimeZoneSet = false;
 CXFA_TimeZoneProvider::CXFA_TimeZoneProvider() {
   if (!g_bProviderTimeZoneSet) {
     g_bProviderTimeZoneSet = true;
+#if defined(OS_BSD)
+    time_t now = time(nullptr);
+    struct tm tm = {};
+
+    localtime_r(&now, &tm);
+    g_lTimeZoneOffset = tm.tm_gmtoff;
+#else
     TZSET();
+#endif
   }
+#if defined(OS_BSD)
+  tz_minutes_ = static_cast<int8_t>((abs(g_lTimeZoneOffset) % 3600) / 60);
+#else
   tz_minutes_ = TIMEZONE / -60;
+#endif
 }
 
 CXFA_TimeZoneProvider::~CXFA_TimeZoneProvider() = default;
