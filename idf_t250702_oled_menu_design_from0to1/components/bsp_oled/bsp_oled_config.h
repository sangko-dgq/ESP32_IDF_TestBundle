


#ifndef BSP_OLED_CONFIG
#define BSP_OLED_CONFIG



/*参数宏定义*********************/

/*FontSize参数取值*/
/*此参数值不仅用于判断，而且用于计算横向字符偏移，默认值为字体像素宽度*/
#define OLED_8X16				8
#define OLED_6X8				6

/*IsFilled参数数值*/
#define OLED_UNFILLED			0
#define OLED_FILLED				1

/* OLED尺寸 0.96/1.3 */
#define OLED_USE_0p96 0
#define OLED_USE_1p3 1


/* OLED 引脚定义 */
#define OLED_I2C I2C_NUM_0
#define OLED_SCL GPIO_NUM_22
#define OLED_SDA GPIO_NUM_21

#define OLED_ADD 0x78 // 地址，OLED模块背面有写
#define OLED_SPEED 400000
#define DELAY_TIME 3000
/*********************参数宏定义*/





#endif // BSP_OLED_CONFIG