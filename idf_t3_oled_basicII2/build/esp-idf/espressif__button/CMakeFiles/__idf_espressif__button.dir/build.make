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
include esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/depend.make

# Include the progress variables for this target.
include esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/flags.make

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/flags.make
esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj: ../managed_components/espressif__button/button_gpio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_gpio.c

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_espressif__button.dir/button_gpio.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_gpio.c > CMakeFiles/__idf_espressif__button.dir/button_gpio.c.i

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_espressif__button.dir/button_gpio.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_gpio.c -o CMakeFiles/__idf_espressif__button.dir/button_gpio.c.s

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/flags.make
esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj: ../managed_components/espressif__button/iot_button.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/iot_button.c

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_espressif__button.dir/iot_button.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/iot_button.c > CMakeFiles/__idf_espressif__button.dir/iot_button.c.i

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_espressif__button.dir/iot_button.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/iot_button.c -o CMakeFiles/__idf_espressif__button.dir/iot_button.c.s

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/flags.make
esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj: ../managed_components/espressif__button/button_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_matrix.c

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_espressif__button.dir/button_matrix.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_matrix.c > CMakeFiles/__idf_espressif__button.dir/button_matrix.c.i

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_espressif__button.dir/button_matrix.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_matrix.c -o CMakeFiles/__idf_espressif__button.dir/button_matrix.c.s

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/flags.make
esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj: ../managed_components/espressif__button/button_adc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj   -c /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_adc.c

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_espressif__button.dir/button_adc.c.i"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_adc.c > CMakeFiles/__idf_espressif__button.dir/button_adc.c.i

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_espressif__button.dir/button_adc.c.s"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && /home/sangko/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button/button_adc.c -o CMakeFiles/__idf_espressif__button.dir/button_adc.c.s

# Object files for target __idf_espressif__button
__idf_espressif__button_OBJECTS = \
"CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj" \
"CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj" \
"CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj" \
"CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj"

# External object files for target __idf_espressif__button
__idf_espressif__button_EXTERNAL_OBJECTS =

esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_gpio.c.obj
esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/iot_button.c.obj
esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_matrix.c.obj
esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/button_adc.c.obj
esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/build.make
esp-idf/espressif__button/libespressif__button.a: esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libespressif__button.a"
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && $(CMAKE_COMMAND) -P CMakeFiles/__idf_espressif__button.dir/cmake_clean_target.cmake
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_espressif__button.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/build: esp-idf/espressif__button/libespressif__button.a

.PHONY : esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/build

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/clean:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button && $(CMAKE_COMMAND) -P CMakeFiles/__idf_espressif__button.dir/cmake_clean.cmake
.PHONY : esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/clean

esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/depend:
	cd /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2 /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/managed_components/espressif__button /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button /home/sangko/esp32_dev/esp-test/my-test/idf_t3_oled_basicII2/build/esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/espressif__button/CMakeFiles/__idf_espressif__button.dir/depend

