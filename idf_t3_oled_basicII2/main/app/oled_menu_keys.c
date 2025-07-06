#include "oled_menu_keys.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <portmacro.h>

#include "esp_log.h"



/**
 * @brief 初始化按键 GPIO 并验证状态
 */
void KEY_Init(void)
{
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pin_bit_mask = (1ULL << KEY_OK_PIN) | 
                        (1ULL << KEY_DOWN_PIN) | 
                        (1ULL << KEY_UP_PIN) |
                        (1ULL << KEY_LEFT_PIN) | 
                        (1ULL << KEY_RIGHT_PIN)
    };
    gpio_config(&io_conf);
    
    // 验证引脚初始化状态
    vTaskDelay(100 / portTICK_PERIOD_MS);  // 等待初始化稳定
    ESP_LOGI("KEYS", "GPIO initialization complete. Pin states:");
    ESP_LOGI("KEYS", "OK: %d, DOWN: %d, UP: %d, LEFT: %d, RIGHT: %d",
             gpio_get_level(KEY_OK_PIN),
             gpio_get_level(KEY_DOWN_PIN),
             gpio_get_level(KEY_UP_PIN),
             gpio_get_level(KEY_LEFT_PIN),
             gpio_get_level(KEY_RIGHT_PIN));
}

/**
 * @brief 非阻塞式按键读取（带状态机消抖）
 * @return uint8_t 按键值（0=无按键，1-5=对应按键）
 */
uint8_t read_key(void)
{
    // 静态变量记录按键状态（0=未按下，1=消抖中，2=已按下等待释放）
    static uint8_t key_states[5] = {0};
    // 记录首次检测到低电平的时间
    static uint32_t key_down_time[5] = {0};
    // 消抖时间（单位：tick）
    const uint32_t debounce_ticks = pdMS_TO_TICKS(20);
    // 按键释放等待时间（单位：tick）
    const uint32_t release_ticks = pdMS_TO_TICKS(10);
    
    // 按键GPIO数组
    const uint32_t gpio_pins[5] = {
        KEY_DOWN_PIN, KEY_LEFT_PIN, KEY_OK_PIN, KEY_RIGHT_PIN, KEY_UP_PIN
    };
    
    uint32_t current_ticks = xTaskGetTickCount();
    
    // 遍历所有按键
    for (int i = 0; i < 5; i++) {
        uint8_t pin_level = gpio_get_level(gpio_pins[i]);
        
        // 状态机逻辑
        switch (key_states[i]) {
            case 0:  // 未按下状态
                if (pin_level == 0) {  // 检测到低电平
                    key_down_time[i] = current_ticks;
                    key_states[i] = 1;  // 进入消抖状态
                    ESP_LOGI("KEYS", "Key %d detected (debouncing...)", i+1);
                }
                break;
                
            case 1:  // 消抖状态
                if (pin_level == 0 && (current_ticks - key_down_time[i] >= debounce_ticks)) {
                    key_states[i] = 2;  // 消抖完成，等待释放
                    ESP_LOGI("KEYS", "Key %d confirmed (press)", i+1);
                } else if (pin_level == 1) {
                    key_states[i] = 0;  // 未通过消抖，恢复初始状态
                }
                break;
                
            case 2:  // 已按下等待释放状态
                if (pin_level == 1) {  // 检测到按键释放
                    key_states[i] = 0;  // 恢复初始状态
                    ESP_LOGI("KEYS", "Key %d released (return value: %d)", i+1, i+1);
                    return i + 1;  // 返回按键值
                }
                break;
        }
    }
    
    return 0;  // 无按键按下
}