--- base/process/process_util_unittest.cc.orig	2020-11-13 06:36:34 UTC
+++ base/process/process_util_unittest.cc
@@ -1307,11 +1307,11 @@ std::string TestLaunchProcess(const CommandLine& cmdli
   options.fds_to_remap.emplace_back(fds[1], STDOUT_FILENO);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   options.clone_flags = clone_flags;
 #else
   CHECK_EQ(0, clone_flags);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   EXPECT_TRUE(LaunchProcess(cmdline, options).IsValid());
   write_pipe.Close();
@@ -1377,11 +1377,11 @@ TEST_F(ProcessUtilTest, LaunchProcess) {
   EXPECT_EQ("wibble", TestLaunchProcess(kPrintEnvCommand, env_changes,
                                         no_clear_environ, no_clone_flags));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Test a non-trival value for clone_flags.
   EXPECT_EQ("wibble", TestLaunchProcess(kPrintEnvCommand, env_changes,
                                         no_clear_environ, CLONE_FS));
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   EXPECT_EQ("wibble",
             TestLaunchProcess(kPrintEnvCommand, env_changes,
@@ -1391,7 +1391,7 @@ TEST_F(ProcessUtilTest, LaunchProcess) {
                                   true /* clear_environ */, no_clone_flags));
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 MULTIPROCESS_TEST_MAIN(CheckPidProcess) {
   const pid_t kInitPid = 1;
   const pid_t pid = syscall(__NR_getpid);
@@ -1452,6 +1452,6 @@ TEST_F(ProcessUtilTest, InvalidCurrentDirectory) {
   EXPECT_TRUE(process.WaitForExit(&exit_code));
   EXPECT_NE(kSuccess, exit_code);
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace base
