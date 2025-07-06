
#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

////////////

// #define TEST_DHT 
#define TEST_LVGL

////////////


/* 
  ===================================
  -----------------LVGL & LCD
  ===================================                     
*/
#ifdef TEST_LVGL
#include "lvgl.h"
#include "lv_port.h"
#include "lv_demos.h"

#include "st7789_driver.h"
#endif


/* 
  ===================================
  -----------------DHT11
  ===================================                     
*/
#ifdef TEST_DHT
#include <nvs_flash.h>
#include "esp32/rom/ets_sys.h"

#include <esp_log.h>

#include "dht11.h"
#define DHT11_GPIO 13 // DHT11引脚定义
const static char *TAG = "DHT11_Demo";
int temp = 0, hum = 0; // 温度 湿度变量

void init_dht11()
{
    ESP_ERROR_CHECK(nvs_flash_init());
    vTaskDelay(100 / portTICK_PERIOD_MS);

    ESP_LOGI(TAG, "[APP] APP Is Start!~\r\n");
    ESP_LOGI(TAG, "[APP] IDF Version is %d.%d.%d", ESP_IDF_VERSION_MAJOR, ESP_IDF_VERSION_MINOR, ESP_IDF_VERSION_PATCH);
    ESP_LOGI(TAG, "[APP] Free memory: %lu bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, "[APP] IDF version: %s", esp_get_idf_version());

    DHT11_Init(DHT11_GPIO);
}
void print_dht11_data()
{
    if (DHT11_StartGet(&temp, &hum))
    {
        ESP_LOGI(TAG, "temp->%i.%i C     hum->%i%%", temp / 10, temp % 10, hum);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
#endif

/* 
  ===================================
  -----------------MAIN
  ===================================                     
*/
void app_main(void)
{
#ifdef TEST_LVGL
    lv_port_init();
    st7789_lcd_backlight(1);
    lv_demo_benchmark();
#endif

#ifdef TEST_DHT
    init_dht11();
#endif

    while (1)
    {
#ifdef TEST_LVGL
        lv_task_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
#endif

#ifdef TEST_DHT
        print_dht11_data();
#endif
    }
}
