--- content/renderer/render_thread_impl.cc.orig	2021-12-31 00:57:32 UTC
+++ content/renderer/render_thread_impl.cc
@@ -190,7 +190,7 @@
 
 #if defined(OS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !defined(OS_BSD)
 #include <malloc.h>
 #endif
 
@@ -723,7 +723,7 @@ void RenderThreadImpl::Init() {
                        compositor_thread_pipeline_.get()));
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   categorized_worker_pool_->SetBackgroundingCallback(
       main_thread_scheduler_->DefaultTaskRunner(),
       base::BindOnce(
@@ -746,7 +746,7 @@ void RenderThreadImpl::Init() {
   base::DiscardableMemoryAllocator::SetInstance(
       discardable_memory_allocator_.get());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           blink::features::kBlinkCompositorUseDisplayThreadPriority)) {
     render_message_filter()->SetThreadPriority(
@@ -1077,11 +1077,11 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
 
   const bool enable_video_decode_accelerator =
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       base::FeatureList::IsEnabled(media::kVaapiVideoDecodeLinux) &&
 #else
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode) &&
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
       (gpu_channel_host->gpu_feature_info()
            .status_values[gpu::GPU_FEATURE_TYPE_ACCELERATED_VIDEO_DECODE] ==
        gpu::kGpuFeatureStatusEnabled);
@@ -1105,7 +1105,7 @@ media::GpuVideoAcceleratorFactories* RenderThreadImpl:
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames);
 #else
       cmd_line->HasSwitch(switches::kEnableGpuMemoryBufferVideoFrames);
-#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) ||
+#endif  // defined(OS_MAC) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
         // defined(OS_WIN)
   const bool enable_media_stream_gpu_memory_buffers =
       enable_gpu_memory_buffers &&
