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

# Include any dependencies generated for this target.
include esp-idf/test/CMakeFiles/__idf_test.dir/depend.make

# Include the progress variables for this target.
include esp-idf/test/CMakeFiles/__idf_test.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/test/CMakeFiles/__idf_test.dir/flags.make

esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.obj: esp-idf/test/CMakeFiles/__idf_test.dir/flags.make
esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.obj: ../components/test/button_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_test.dir/button_test.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/components/test/button_test.c

esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_test.dir/button_test.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/components/test/button_test.c > CMakeFiles/__idf_test.dir/button_test.c.i

esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_test.dir/button_test.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/components/test/button_test.c -o CMakeFiles/__idf_test.dir/button_test.c.s

# Object files for target __idf_test
__idf_test_OBJECTS = \
"CMakeFiles/__idf_test.dir/button_test.c.obj"

# External object files for target __idf_test
__idf_test_EXTERNAL_OBJECTS =

esp-idf/test/libtest.a: esp-idf/test/CMakeFiles/__idf_test.dir/button_test.c.obj
esp-idf/test/libtest.a: esp-idf/test/CMakeFiles/__idf_test.dir/build.make
esp-idf/test/libtest.a: esp-idf/test/CMakeFiles/__idf_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtest.a"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && $(CMAKE_COMMAND) -P CMakeFiles/__idf_test.dir/cmake_clean_target.cmake
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/test/CMakeFiles/__idf_test.dir/build: esp-idf/test/libtest.a

.PHONY : esp-idf/test/CMakeFiles/__idf_test.dir/build

esp-idf/test/CMakeFiles/__idf_test.dir/clean:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test && $(CMAKE_COMMAND) -P CMakeFiles/__idf_test.dir/cmake_clean.cmake
.PHONY : esp-idf/test/CMakeFiles/__idf_test.dir/clean

esp-idf/test/CMakeFiles/__idf_test.dir/depend:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1 /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/components/test /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/test/CMakeFiles/__idf_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/test/CMakeFiles/__idf_test.dir/depend

