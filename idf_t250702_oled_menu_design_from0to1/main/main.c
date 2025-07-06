#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "button_test.h"


void app_main(void)
{

    //LED初始化
    button_led_init();
    //简单按键例程
    // xTaskCreatePinnedToCore(simple_btn_test,"simple_btn_test",2048,NULL,3,NULL,1);
    //较通用的按键例程
    xTaskCreatePinnedToCore(complete_btn_test,"complete_btn_test",2048,NULL,3,NULL,1);

    while(1)
    {

    }
}
