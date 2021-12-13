--- cc/test/layer_tree_test.cc.orig	2021-12-07 05:33:15 UTC
+++ cc/test/layer_tree_test.cc
@@ -679,7 +679,7 @@ LayerTreeTest::LayerTreeTest(viz::RendererType rendere
     init_vulkan = true;
   } else if (renderer_type_ == viz::RendererType::kSkiaDawn) {
     scoped_feature_list_.InitAndEnableFeature(features::kSkiaDawn);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     init_vulkan = true;
 #elif defined(OS_WIN)
     // TODO(rivr): Initialize D3D12 for Windows.
