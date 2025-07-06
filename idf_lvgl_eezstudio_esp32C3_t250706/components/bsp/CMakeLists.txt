idf_component_register(SRCS  "bsp_gpio.c"
                        SRCS "bsp_i2c.c"
                        SRCS "bsp_key.c"
                        SRCS "bsp_buzzer.c"
                    INCLUDE_DIRS "."
                    REQUIRES driver lvgl)
