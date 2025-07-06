idf_component_register(
    SRCS "bsp_oled.c" "bsp_oled_data.c"    # 具体实现源码
    INCLUDE_DIRS "."       # 头文件搜索路径
    REQUIRES driver       # 依赖的其他组件
)