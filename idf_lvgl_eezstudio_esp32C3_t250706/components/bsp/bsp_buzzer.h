
#ifndef __BSP_BUZZER_H__
#define __BSP_BUZZER_H__   


#include <stdio.h>



#define BUZZER_GPIO GPIO_NUM_33 //蜂鸣器GPIO


void bsp_buzzer_init(void);
void bsp_buzzer_on(void);
void bsp_buzzer_off(void); 


void bsp_buzzer_beep(uint32_t duration_ms); // 蜂鸣器发出指定时长的蜂鸣声


#endif