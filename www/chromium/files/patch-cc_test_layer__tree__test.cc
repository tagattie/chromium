--- cc/test/layer_tree_test.cc.orig	2020-10-07 16:38:34 UTC
+++ cc/test/layer_tree_test.cc
@@ -665,7 +665,7 @@ LayerTreeTest::LayerTreeTest(TestRendererType renderer
     init_vulkan = true;
   } else if (renderer_type_ == TestRendererType::kSkiaDawn) {
     scoped_feature_list_.InitAndEnableFeature(features::kSkiaDawn);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     init_vulkan = true;
 #elif defined(OS_WIN)
     // TODO(sgilhuly): Initialize D3D12 for Windows.
