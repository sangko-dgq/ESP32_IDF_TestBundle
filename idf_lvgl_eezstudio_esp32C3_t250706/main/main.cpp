/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "ui.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "myi2c.h"
#include "lvgl_demo_ui.h"

#include "bsp_key.h"
#ifdef __cplusplus
}
#endif

extern "C" void app_main(void)
{

    app_init();

    while (1)
    {
        ui_tick();
        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        vTaskDelay(pdMS_TO_TICKS(10));
        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        lv_timer_handler();
    }
}
