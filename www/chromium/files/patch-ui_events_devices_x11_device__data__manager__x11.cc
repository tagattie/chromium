--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2020-11-13 06:37:05 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -850,6 +850,7 @@ void DeviceDataManagerX11::DisableDevice(x11::Input::D
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(x11::Input::DeviceId deviceid) {
