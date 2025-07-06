idf_component_register(
    SRCS "OLED.c" "OLED_Data.c"       # 源文件路径
    INCLUDE_DIRS "."       # 头文件搜索路径
    REQUIRES driver       # 依赖的其他组件
)