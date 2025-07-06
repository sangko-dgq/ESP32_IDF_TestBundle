
# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly


cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS ./components)


include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(idf_t250702_oled_menu_design_from0to1)


idf_build_set_property(COMPILE_OPTIONS "-Wno-error" APPEND) #-Wno-error 选项的核心作用是：禁止将警告（Warnings）升级为错误（Errors）。


#message(idf_build_get_property  COMPONENTS) #output 打印此次构建中包含的所有组件的名称，可用于检查组件是否被包含