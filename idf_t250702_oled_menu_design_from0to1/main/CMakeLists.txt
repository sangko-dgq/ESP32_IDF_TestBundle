idf_component_register(SRCS "main.c"
        INCLUDE_DIRS "."
        REQUIRES  #main组件是特殊组件，不需要手动依赖。
)

