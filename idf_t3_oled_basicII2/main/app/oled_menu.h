#ifndef _OLED_MENU_H
#define _OLED_MENU_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 假设 OLED 相关函数定义在 oled.h 中
#include "OLED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 菜单项目结构体
typedef struct
{
    const char *name;  // 菜单项目名称
    void (*func)(void); // 菜单项目回调函数
} MENU_Item_t;

// 菜单结构体
typedef struct MENU_t
{
    MENU_Item_t *item;  // 菜单项目数组
    uint8_t item_num;   // 菜单项目数量
    uint8_t cur_item;   // 当前选中的菜单项目
    uint8_t menu_flag;  // 菜单层级标志
    struct MENU_t *sub2_menu; // 指向二级菜单的指针
    struct MENU_t *sub3_menu; // 指向三级菜单的指针
} MENU_t;

// 菜单回调函数声明
void Item1_Callback(void);
void Item2_Callback(void);
void Item3_Callback(void);
void Item4_Callback(void);
void Item5_Callback(void);
void Item6_Callback(void);

void SUB1_Callback(void);
void SUB2_Callback(void);
void SUB3_Callback(void);

void Third1_Callback(void);
void Third2_Callback(void);
void Third3_Callback(void);
void Third4_Callback(void);

// 初始化菜单
int MENU_Init(void);
// 菜单按键扫描
void MENU_KeyScan(uint8_t key);
// 进入子菜单
void MENU_INPUT(uint8_t cur_item_ok, MENU_t menu_ok, MENU_t *sub_menu_ok, uint8_t cur_item_next_ok, uint8_t menu_flag_ok);
// 返回上一级菜单
void MENU_RETURN(void);
// 文本菜单显示
void MENU_Text_Display(void);
// 图片菜单显示
void MENU_Iamge_Display(uint8_t iamge_index);
// 菜单显示模式切换
void MENU_Mode_chang(void);

#endif