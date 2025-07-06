#ifndef OLED_MENU_KEYS_H
#define OLOLED_MENU_KEYS_H

#include "driver/gpio.h"  // 引入 ESP-IDF 的 GPIO 驱动库
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 定义按键引脚
#define KEY_OK_PIN     GPIO_NUM_25
#define KEY_DOWN_PIN   GPIO_NUM_26
#define KEY_UP_PIN     GPIO_NUM_27

#define KEY_LEFT_PIN   GPIO_NUM_13
#define KEY_RIGHT_PIN  GPIO_NUM_14


// 初始化按键
void KEY_Init(void);
// 读取按键值
uint8_t read_key(void);

#endif //OLED_MENU_KEYS_H