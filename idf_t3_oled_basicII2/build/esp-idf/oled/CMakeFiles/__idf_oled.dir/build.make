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
CMAKE_SOURCE_DIR = /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build

# Include any dependencies generated for this target.
include esp-idf/oled/CMakeFiles/__idf_oled.dir/depend.make

# Include the progress variables for this target.
include esp-idf/oled/CMakeFiles/__idf_oled.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/oled/CMakeFiles/__idf_oled.dir/flags.make

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.obj: esp-idf/oled/CMakeFiles/__idf_oled.dir/flags.make
esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.obj: ../components/oled/OLED.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_oled.dir/OLED.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED.c

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_oled.dir/OLED.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED.c > CMakeFiles/__idf_oled.dir/OLED.c.i

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_oled.dir/OLED.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED.c -o CMakeFiles/__idf_oled.dir/OLED.c.s

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.obj: esp-idf/oled/CMakeFiles/__idf_oled.dir/flags.make
esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.obj: ../components/oled/OLED_Data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_oled.dir/OLED_Data.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED_Data.c

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_oled.dir/OLED_Data.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED_Data.c > CMakeFiles/__idf_oled.dir/OLED_Data.c.i

esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_oled.dir/OLED_Data.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled/OLED_Data.c -o CMakeFiles/__idf_oled.dir/OLED_Data.c.s

# Object files for target __idf_oled
__idf_oled_OBJECTS = \
"CMakeFiles/__idf_oled.dir/OLED.c.obj" \
"CMakeFiles/__idf_oled.dir/OLED_Data.c.obj"

# External object files for target __idf_oled
__idf_oled_EXTERNAL_OBJECTS =

esp-idf/oled/liboled.a: esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED.c.obj
esp-idf/oled/liboled.a: esp-idf/oled/CMakeFiles/__idf_oled.dir/OLED_Data.c.obj
esp-idf/oled/liboled.a: esp-idf/oled/CMakeFiles/__idf_oled.dir/build.make
esp-idf/oled/liboled.a: esp-idf/oled/CMakeFiles/__idf_oled.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library liboled.a"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && $(CMAKE_COMMAND) -P CMakeFiles/__idf_oled.dir/cmake_clean_target.cmake
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_oled.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/oled/CMakeFiles/__idf_oled.dir/build: esp-idf/oled/liboled.a

.PHONY : esp-idf/oled/CMakeFiles/__idf_oled.dir/build

esp-idf/oled/CMakeFiles/__idf_oled.dir/clean:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled && $(CMAKE_COMMAND) -P CMakeFiles/__idf_oled.dir/cmake_clean.cmake
.PHONY : esp-idf/oled/CMakeFiles/__idf_oled.dir/clean

esp-idf/oled/CMakeFiles/__idf_oled.dir/depend:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2 /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/components/oled /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/oled/CMakeFiles/__idf_oled.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/oled/CMakeFiles/__idf_oled.dir/depend

