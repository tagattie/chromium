--- tools/json_schema_compiler/feature_compiler.py.orig	2020-10-07 16:39:09 UTC
+++ tools/json_schema_compiler/feature_compiler.py
@@ -242,6 +242,7 @@ FEATURE_GRAMMAR = ({
                 'chromeos': 'Feature::CHROMEOS_PLATFORM',
                 'lacros': 'Feature::LACROS_PLATFORM',
                 'linux': 'Feature::LINUX_PLATFORM',
+                'bsd': 'Feature::LINUX_PLATFORM',
                 'mac': 'Feature::MACOSX_PLATFORM',
                 'win': 'Feature::WIN_PLATFORM',
             }
