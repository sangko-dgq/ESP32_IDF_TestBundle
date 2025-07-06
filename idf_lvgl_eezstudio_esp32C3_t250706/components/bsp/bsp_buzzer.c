
#include "bsp_buzzer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void bsp_buzzer_init(void)
{
    // 初始化蜂鸣器 GPIO
    gpio_reset_pin(BUZZER_GPIO);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BUZZER_GPIO, 0); // 默认关闭蜂鸣器
}
void bsp_buzzer_on(void)
{
    // 打开蜂鸣器
    gpio_set_level(BUZZER_GPIO, 1);
}
void bsp_buzzer_off(void)
{
    // 关闭蜂鸣器
    gpio_set_level(BUZZER_GPIO, 0);
}   

/**
 * @brief 蜂鸣器发出指定时长的蜂鸣声
 * @param duration_ms 蜂鸣时长，单位为毫秒
 */
void bsp_buzzer_beep(uint32_t duration_ms)
{
    // 打开蜂鸣器
    bsp_buzzer_on();
    // 延时指定时间
    vTaskDelay(pdMS_TO_TICKS(duration_ms));
    // 关闭蜂鸣器
    bsp_buzzer_off();
}