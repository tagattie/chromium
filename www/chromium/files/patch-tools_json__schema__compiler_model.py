--- tools/json_schema_compiler/model.py.orig	2021-12-07 05:34:22 UTC
+++ tools/json_schema_compiler/model.py
@@ -877,6 +877,7 @@ class Platforms(object):
   """Enum of the possible platforms.
   """
   CHROMEOS = _PlatformInfo("chromeos")
+  FREEBSD = _PlatformInfo("freebsd")
   LACROS = _PlatformInfo("lacros")
   LINUX = _PlatformInfo("linux")
   MAC = _PlatformInfo("mac")
