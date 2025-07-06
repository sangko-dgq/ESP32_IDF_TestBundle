#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
const char* TAG = "MAIN";


/*
 * ================================= OLED
 */
// ESP32 PICO D4 默认的 硬件I2C 引脚为 GPIO 21（SDA）和 GPIO 22（SCL）
// 该程序是软件软件模拟I2C,所以引脚可以任意

#include "OLED.h"
#include "app/oled_menu.h"
#include "app/oled_menu_keys.h"

#define OLED_I2C I2C_NUM_0
#define OLED_SCL GPIO_NUM_22
#define OLED_SDA GPIO_NUM_21

#define OLED_ADD 0x78 // OLED模块背面有写
#define OLED_SPEED 400000
#define DELAY_TIME 3000

/*
 *=============================BUTTON(ESP BUTTON BSP)
 */
#include "button_gpio.h"
#include "iot_button.h"

static void button_single_click_cb(void *arg, void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_SINGLE_CLICK");
    MENU_KeyScan(3);
}
void app_main(void)
{
    OLED_Init(OLED_I2C, OLED_ADD, OLED_SCL, OLED_SDA, OLED_SPEED);
    KEY_Init();

    MENU_Init();
    MENU_KeyScan(0);
    ESP_LOGI(TAG, "System initialized successfully");


    // create gpio button
    const button_config_t btn_cfg = {0};
    const button_gpio_config_t btn_gpio_cfg = {
        .gpio_num = 25,
        .active_level = 0,
    };
    button_handle_t gpio_btn = NULL;
    esp_err_t ret = iot_button_new_gpio_device(&btn_cfg, &btn_gpio_cfg, &gpio_btn);
    if (NULL == gpio_btn)
    {
         ESP_LOGI(TAG, "Button create failed");
    }
    // CB REGISTER
    iot_button_register_cb(gpio_btn, BUTTON_SINGLE_CLICK, NULL, button_single_click_cb, NULL);
    // START BUTTON
    iot_button_resume();

    uint8_t key;
    const TickType_t delay_ticks = pdMS_TO_TICKS(10); // 10ms延时

    while (1)
    {
        // key = read_key(); // 非阻塞式按键检测

        // if (key)
        // {
        //     // ESP_LOGI("APP", "Key pressed: %d", key);
        //     switch (key)
        //     {
        //     case 1:
        //         MENU_KeyScan(1);
        //         break;
        //     case 2:
        //         MENU_KeyScan(2);
        //         break;
        //     case 3:
        //         MENU_KeyScan(3);
        //         break;
        //     case 4:
        //         MENU_KeyScan(4);
        //         break;
        //     case 5:
        //         MENU_KeyScan(5);
        //         break;
        //     default:
        //         break;
        //     }
        // }

        vTaskDelay(delay_ticks); // 释放CPU，防止看门狗触发
    }
}
