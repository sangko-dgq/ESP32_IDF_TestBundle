# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build

# Utility rule file for save-defconfig.

# Include the progress variables for this target.
include CMakeFiles/save-defconfig.dir/progress.make

CMakeFiles/save-defconfig:
	python /home/sangko/esp32_dev/esp-idf/tools/kconfig_new/prepare_kconfig_files.py --list-separator=semicolon --env-file /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/config.env
	python -m kconfgen --list-separator=semicolon --kconfig /home/sangko/esp32_dev/esp-idf/Kconfig --sdkconfig-rename /home/sangko/esp32_dev/esp-idf/sdkconfig.rename --config /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/sdkconfig --defaults /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/sdkconfig.defaults --env-file /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/config.env --dont-write-deprecated --output savedefconfig /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/sdkconfig.defaults

save-defconfig: CMakeFiles/save-defconfig
save-defconfig: CMakeFiles/save-defconfig.dir/build.make

.PHONY : save-defconfig

# Rule to build all files generated by this target.
CMakeFiles/save-defconfig.dir/build: save-defconfig

.PHONY : CMakeFiles/save-defconfig.dir/build

CMakeFiles/save-defconfig.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/save-defconfig.dir/cmake_clean.cmake
.PHONY : CMakeFiles/save-defconfig.dir/clean

CMakeFiles/save-defconfig.dir/depend:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1 /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1 /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles/save-defconfig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/save-defconfig.dir/depend

