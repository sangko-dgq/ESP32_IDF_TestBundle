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
include esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/depend.make

# Include the progress variables for this target.
include esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj: /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj   -c /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer.c

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer.c > CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.i

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer.c -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.s

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj: /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/ets_timer_legacy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj   -c /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/ets_timer_legacy.c

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/ets_timer_legacy.c > CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.i

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/ets_timer_legacy.c -o CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.s

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj: /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/system_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj   -c /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/system_time.c

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_timer.dir/src/system_time.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/system_time.c > CMakeFiles/__idf_esp_timer.dir/src/system_time.c.i

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_timer.dir/src/system_time.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/system_time.c -o CMakeFiles/__idf_esp_timer.dir/src/system_time.c.s

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj: /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_common.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj   -c /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_common.c

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_common.c > CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.i

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_common.c -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.s

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/flags.make
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj: /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_lac.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj   -c /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_lac.c

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_lac.c > CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.i

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-idf/components/esp_timer/src/esp_timer_impl_lac.c -o CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.s

# Object files for target __idf_esp_timer
__idf_esp_timer_OBJECTS = \
"CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj" \
"CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj" \
"CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj" \
"CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj" \
"CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj"

# External object files for target __idf_esp_timer
__idf_esp_timer_EXTERNAL_OBJECTS =

esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer.c.obj
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/ets_timer_legacy.c.obj
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/system_time.c.obj
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_common.c.obj
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/src/esp_timer_impl_lac.c.obj
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/build.make
esp-idf/esp_timer/libesp_timer.a: esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libesp_timer.a"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_timer.dir/cmake_clean_target.cmake
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_esp_timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/build: esp-idf/esp_timer/libesp_timer.a

.PHONY : esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/build

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/clean:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_timer.dir/cmake_clean.cmake
.PHONY : esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/clean

esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/depend:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1 /home/sangko/esp32_dev/esp-idf/components/esp_timer /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer /home/sangko/esp32_dev/esp-test/my-test/idf_t250702_oled_menu_design_from0to1/build/esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/esp_timer/CMakeFiles/__idf_esp_timer.dir/depend

