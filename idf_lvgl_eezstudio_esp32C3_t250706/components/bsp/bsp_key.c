/*
*********************************************************************************************************
*
*	模块名称 : IO初始化
*	文件名称 : bsp_key.c
*	版    本 : V1.0
*	说    明 : 外部绑定按键
*	修改记录 :
*	版本号          日期        		作者     		说明
*	V1.0           2022-09-08 		  DOUBLE  		 正式发布
*********************************************************************************************************
*/
#include "bsp_key.h"

#define UP_GPIO 27
#define MID_GPIO 26
#define DOWN_GPIO 25 

enum key_type
{
    NC_KEY = 0,
    BIND1_KEY,
    BIND2_KEY,
    USER_KEY_KEY
};
/*
*********************************************************************************************************
*	函 数 名: bsp_gpio_init
*	功能说明: IO初始化
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_key_init(void)
{
    gpio_reset_pin(UP_GPIO);
    gpio_set_direction(UP_GPIO, GPIO_MODE_INPUT);
    gpio_reset_pin(MID_GPIO);
    gpio_set_direction(MID_GPIO, GPIO_MODE_INPUT);
    gpio_reset_pin(DOWN_GPIO);
    gpio_set_direction(DOWN_GPIO, GPIO_MODE_INPUT);
}
/*
*********************************************************************************************************
*	函 数 名: led_on
*	功能说明: 开灯
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
int get_key_gpio(unsigned char num)
{
    int key = 0;
    if (num == 1)
    {
        key = gpio_get_level(UP_GPIO);
    }
    else if (num == 2)
    {
        key = gpio_get_level(MID_GPIO);
    }
    else if (num == 3)
    {
        key = gpio_get_level(DOWN_GPIO);
    }
    return key;
}

/*
*********************************************************************************************************
*	函 数 名: key_num_map
*	功能说明: 绑定按键编号映射成物理按键软编号
*	形    参：无
*	返 回 值: 绑定按键触发值
*********************************************************************************************************
*/
uint8_t key_num_map(uint8_t num)
{
    uint8_t key = num;

    return key;
}
/*
*********************************************************************************************************
*	函 数 名: bind_key_read
*	功能说明: 外接绑定按键 标志值
*	形    参：无
*	返 回 值: 绑定按键触发值
*********************************************************************************************************
*/
uint8_t bind_key_read(const lv_group_t *group)
{
    uint8_t keys = 0;
    static uint8_t key1_status[2] = {0, 0};
    static uint8_t key2_status[2] = {0, 0};
    static uint8_t key3_status[2] = {0, 0};

    if (get_key_gpio(1) == 0)
    {
        key1_status[0] = 1;
    }
    else
    {
        key1_status[0] = 0;
    }
    if (key1_status[0] != key1_status[1])
    {
        key1_status[1] = key1_status[0];
        if (key1_status[1] == 0)
        {
            if (lv_group_get_editing(group) == 1)//TODO:进入编辑模式 ： 聚焦到控件-》按下确认键-》进入编辑模式-》保存编辑（进去焦点切换模式）
                keys = 3;//编辑模式的标志为4
            else
                keys = 2;
        }
    }

    if (get_key_gpio(2) == 0)
    {
        key2_status[0] = 1;
    }
    else
    {
        key2_status[0] = 0;
    }
    if (key2_status[0] != key2_status[1])
    {
        key2_status[1] = key2_status[0];
        if (key2_status[1] == 0)
        {
            if (lv_group_get_editing(group) == 1) 
                keys = 4; //编辑模式的标志为4
            else
                keys = 1;
        }
    }

    if (get_key_gpio(3) == 0)
    {
        key3_status[0] = 1;
    }
    else
    {
        key3_status[0] = 0;
    }
    if (key3_status[0] != key3_status[1])
    {
        key3_status[1] = key3_status[0];
        if (key3_status[1] == 0)
            keys = 5;
    }

    return keys; //返回标志
}
/*
*********************************************************************************************************
*	函 数 名: user_key_read
*	功能说明: 用户按键
*	形    参：无
*	返 回 值: 绑定按键触发值
*********************************************************************************************************
*/
void user_key_read(uint16_t *key, uint16_t *time)
{
    static uint16_t user_status = 0;
    static uint16_t user_time = 0;
    if (get_key_gpio(USER_KEY_KEY) == 0)
    {
        user_status = 1;
        user_time++; // 50ms++
    }
    else
    {
        user_status = 0;
        user_time = 0;
    }
    *key = user_status;
    *time = user_time;
}