--- ./net/dns/dns_config_service_posix_unittest.cc.orig	2014-04-02 21:03:39.000000000 +0200
+++ ./net/dns/dns_config_service_posix_unittest.cc	2014-04-04 01:39:18.000000000 +0200
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include "base/sys_byteorder.h"
 #include "net/dns/dns_config_service_posix.h"
 
