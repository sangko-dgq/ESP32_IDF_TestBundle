# Search for src files
set(UI_DIR ./ui)
file(GLOB_RECURSE UI_SRCS ${UI_DIR}/*.c ${UI_DIR}/*.cpp) 

idf_component_register(SRCS "main.cpp" "myi2c.c" "lvgl_demo_ui.c" ${UI_SRCS}
			       INCLUDE_DIRS "." ${UI_DIR})
add_compile_definitions (LV_LVGL_H_INCLUDE_SIMPLE)


# Compiler options to suppress warnings, applied selectively for C and C++ code
target_compile_options(${COMPONENT_LIB} PUBLIC $<$<COMPILE_LANGUAGE:C>:-Wno-pointer-sign>)
target_compile_options(${COMPONENT_LIB} PUBLIC $<$<COMPILE_LANGUAGE:C>:-Wno-discarded-qualifiers>)
target_compile_options(${COMPONENT_LIB} PUBLIC "-Wno-unused-function")
target_compile_options(${COMPONENT_LIB} PUBLIC "-Wno-unused-variable") # Suppress warnings for unused variables
target_compile_options(${COMPONENT_LIB} PUBLIC "-Wno-cast-function-type")
target_compile_options(${COMPONENT_LIB} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wno-old-style-cast>) # Suppress warnings for old-style casts in C++
target_compile_options(${COMPONENT_LIB} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wno-unused-parameter>) # Suppress warnings for unused parameters, common in C++ interfaces
target_compile_options(${COMPONENT_LIB} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-Wno-deprecated-enum-enum-conversion>) # Suppress warnings for deprecated enum conversions in C++
target_compile_options(${COMPONENT_LIB} PRIVATE "-Wno-stringop-truncation")
