#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

///////////////////////////////////////////////////////////////
//                          LED BREATH
// 实现ESP32 通过 LEDC（LED 控制器）外设控制 LED 呼吸效果的功能。
// 主要包含以下部分：
//     初始化配置：设置 LEDC 定时器和通道参数
//     呼吸控制逻辑：使用事件组和回调函数实现亮度渐变循环
//     中断处理：在亮度渐变完成时触发回调函数,进行下一次亮度渐变
//     任务管理：创建独立任务处理 LED 控制逻辑
///////////////////////////////////////////////////////////////
#include "driver/gpio.h"
#include "driver/ledc.h"

/* GPIO DEFINE */
#define GPIO_LED_PWM GPIO_NUM_13

static EventGroupHandle_t ledc_event_handle;
#define FULL_EV_BIT BIT0
#define EMPTY_EV_BIT BIT1

// CALLBACK when ledc finished
bool IRAM_ATTR ledc_finish_cb(const ledc_cb_param_t *ledc_cb_param, void *user_arg)
{
    BaseType_t taskWoken = pdFALSE;
    if (ledc_cb_param->duty)
    {
        xEventGroupSetBitsFromISR(ledc_event_handle, FULL_EV_BIT, &taskWoken);
    }
    else
    {
        xEventGroupSetBitsFromISR(ledc_event_handle, EMPTY_EV_BIT, &taskWoken);
    }
    return taskWoken;
}

// TASK
void task_led_breath()
{
    EventBits_t eventBits;
    while (1)
    {
        // 等待亮度变化完成事件
        eventBits = xEventGroupWaitBits(
            ledc_event_handle,
            FULL_EV_BIT | EMPTY_EV_BIT,
            pdTRUE,         // 清除已设置的事件位
            pdFALSE,        // 不要求所有位都设置
            portMAX_DELAY); // 无限等待，避免不必要的超时

        if (eventBits & FULL_EV_BIT)
        {
            // 从最亮渐变为熄灭
            ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 0, 2000);
            ledc_fade_start(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, LEDC_FADE_NO_WAIT);
        }
        if (eventBits & EMPTY_EV_BIT)
        {
            // 从熄灭渐变为最亮
            ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 8191, 2000);
            ledc_fade_start(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, LEDC_FADE_NO_WAIT);
        }
    }
}

// INIT
void init_led_breath()
{
    // 配置LEDC定时器
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .timer_num = LEDC_TIMER_0,
        .clk_cfg = LEDC_AUTO_CLK,
        .freq_hz = 5000,                      // 5000hz
        .duty_resolution = LEDC_TIMER_13_BIT, // 占空比分辨率
    };
    ledc_timer_config(&ledc_timer);

    // 配置LEDC通道
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .timer_sel = LEDC_TIMER_0,
        .gpio_num = GPIO_LED_PWM,
        .duty = 0,
        .intr_type = LEDC_INTR_DISABLE,
    };
    ledc_channel_config(&ledc_channel);

    // 安装渐变功能
    ledc_fade_func_install(0);

    // 创建事件组用于同步
    ledc_event_handle = xEventGroupCreate();

    // 注册回调函数（只注册一次）
    ledc_cbs_t ledc_cbs = {
        .fade_cb = ledc_finish_cb,
    };
    ledc_cb_register(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, &ledc_cbs, NULL);

    // 启动第一次渐变（从熄灭到最亮）
    ledc_set_fade_with_time(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 8191, 2000);
    ledc_fade_start(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, LEDC_FADE_NO_WAIT);

    // 创建LED控制任务
    xTaskCreatePinnedToCore(task_led_breath, "task_led_breath", 2048, NULL, 3, NULL, 1);
}

///////////////////////////////////////////////////////////////
//                          LED LEVLE TOGGLE
//实习LED的电平翻转，基于 gpio_set_level API函数
///////////////////////////////////////////////////////////////
#include "driver/gpio.h"

/* GPIO LOG TAG */
static const char *TAG = "LED_CONTROL";
/* GPIO DEFINE */
#define GPIO_LED_TEST GPIO_NUM_12
/* GPIO TASK DEFINE */
void task_led_toggle()
{
    int gpio_level = 0;
    while (1)
    {
        gpio_level = gpio_level ? 0 : 1;
        if (gpio_level)
            ESP_LOGI(TAG, "LED is ON");
        else
            ESP_LOGI(TAG, "LED is OFF");
        gpio_set_level(GPIO_LED_TEST, gpio_level);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// INIT
void init_led_toggle()
{
    gpio_config_t gpio_led_config = {
        .pin_bit_mask = (1 << GPIO_LED_TEST),
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&gpio_led_config);
    xTaskCreatePinnedToCore(task_led_toggle, "task_led_toggle", 2048, NULL, 3, NULL, 1);
}

///////////////////////////////////////////////////////////////
//                          MAIN
///////////////////////////////////////////////////////////////
void app_main(void)
{
    init_led_breath();
}
