--- chromecast/renderer/cast_content_renderer_client.cc.orig	2021-12-31 00:57:27 UTC
+++ chromecast/renderer/cast_content_renderer_client.cc
@@ -206,7 +206,7 @@ void CastContentRendererClient::RenderFrameCreated(
   dispatcher->OnRenderFrameCreated(render_frame);
 #endif
 
-#if (defined(OS_LINUX) || defined(OS_CHROMEOS)) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && defined(USE_OZONE)
   // JsChannelBindings destroys itself when the RenderFrame is destroyed.
   JsChannelBindings::Create(render_frame);
 #endif
