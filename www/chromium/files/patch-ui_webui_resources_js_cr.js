--- ui/webui/resources/js/cr.js.orig	2020-11-13 06:37:06 UTC
+++ ui/webui/resources/js/cr.js
@@ -430,6 +430,11 @@ var cr = cr || function(global) {
     get isMac() {
       return /Mac/.test(navigator.platform);
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
 
     /** Whether this is on the Windows platform or not. */
     get isWindows() {
