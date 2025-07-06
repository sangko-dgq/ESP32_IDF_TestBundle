
/*********************************************************
 * @file lvgl_demo_ui.c
 * @brief 仪表盘演示界面及 ESP32 屏幕驱动初始化
 * 功能：
 *   - UI 创建与动画
 *   - 屏幕及 LVGL 驱动初始化与注册
 *   - 触摸驱动注册
 * 平台：ESP32 （测试通过：ESP32-PICO-D4、ESP32C3）
 * 支持：可选ILI9341, GC9A01, ST7789 LCD 控制器
 * 接口：硬件 SPI 驱动显示，I2C 驱动触摸
 **********************************************************/

/*
 * 板块 1：LVGL 仪表盘演示 UI
 * 作用：创建仪表盘和旋转按钮界面，并实现动画效果
 */
#include "lvgl.h"

// 仪表盘对象、按钮对象、屏幕旋转状态
static lv_obj_t *meter;
static lv_obj_t *btn;
static lv_disp_rot_t rotation = LV_DISP_ROT_NONE;

// 仪表盘动画回调：设置指针值
static void set_value(void *indic, int32_t v)
{
    lv_meter_set_indicator_end_value(meter, indic, v);
}

// 按钮事件回调：切换屏幕旋转方向
static void btn_cb(lv_event_t *e)
{
    lv_disp_t *disp = lv_event_get_user_data(e);
    rotation++;
    if (rotation > LV_DISP_ROT_270)
    {
        rotation = LV_DISP_ROT_NONE;
    }
    lv_disp_set_rotation(disp, rotation);
}

// 创建 LVGL 仪表盘和旋转按钮，并添加动画
void example_lvgl_demo_ui(lv_disp_t *disp)
{
    // 获取当前活动屏幕
    lv_obj_t *scr = lv_disp_get_scr_act(disp);
    // 创建仪表盘对象
    meter = lv_meter_create(scr);
    lv_obj_center(meter);
    lv_obj_set_size(meter, 200, 200);

    // 添加刻度尺
    lv_meter_scale_t *scale = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale, 41, 2, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_major_ticks(meter, scale, 8, 4, 15, lv_color_black(), 10);

    lv_meter_indicator_t *indic;

    // 添加蓝色弧线（起始部分）
    indic = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_meter_set_indicator_start_value(meter, indic, 0);
    lv_meter_set_indicator_end_value(meter, indic, 20);

    // 起始刻度线变蓝
    indic = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_BLUE), false, 0);
    lv_meter_set_indicator_start_value(meter, indic, 0);
    lv_meter_set_indicator_end_value(meter, indic, 20);

    // 添加红色弧线（末尾部分）
    indic = lv_meter_add_arc(meter, scale, 3, lv_palette_main(LV_PALETTE_RED), 0);
    lv_meter_set_indicator_start_value(meter, indic, 80);
    lv_meter_set_indicator_end_value(meter, indic, 100);

    // 末尾刻度线变红
    indic = lv_meter_add_scale_lines(meter, scale, lv_palette_main(LV_PALETTE_RED), lv_palette_main(LV_PALETTE_RED), false, 0);
    lv_meter_set_indicator_start_value(meter, indic, 80);
    lv_meter_set_indicator_end_value(meter, indic, 100);

    // 添加指针
    indic = lv_meter_add_needle_line(meter, scale, 4, lv_palette_main(LV_PALETTE_GREY), -10);

    // 创建旋转按钮
    btn = lv_btn_create(scr);
    lv_obj_t *lbl = lv_label_create(btn);
    lv_label_set_text_static(lbl, LV_SYMBOL_REFRESH " ROTATE");
    lv_obj_align(btn, LV_ALIGN_BOTTOM_LEFT, 30, -30);
    // 按钮事件绑定
    lv_obj_add_event_cb(btn, btn_cb, LV_EVENT_CLICKED, disp);

    // 创建仪表盘动画
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_var(&a, indic);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_time(&a, 2000);
    lv_anim_set_repeat_delay(&a, 100);
    lv_anim_set_playback_time(&a, 500);
    lv_anim_set_playback_delay(&a, 100);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);
}

/*
 * 板块 2：ESP32 屏幕与 LVGL 驱动初始化
 * 作用：初始化硬件和 LVGL 驱动，注册显示和输入设备
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "myi2c.h"
#include "lv_demos.h"

#include "screens.h"
#include "ui.h"

#if CONFIG_EXAMPLE_LCD_CONTROLLER_ILI9341
#include "esp_lcd_ili9341.h"
#elif CONFIG_EXAMPLE_LCD_CONTROLLER_GC9A01
#include "esp_lcd_gc9a01.h"
#endif

#if CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_STMPE610
#include "esp_lcd_touch_stmpe610.h"
#elif CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_FT6336
#include "esp_lcd_touch_ft5x06.h"
#endif

static const char *TAG = "example";

// ========================== 屏幕硬件参数配置 ==========================
// 作用：根据实际硬件修改 SPI、GPIO、分辨率等参数
#define LCD_HOST SPI2_HOST
#define EXAMPLE_LCD_PIXEL_CLOCK_HZ (20 * 1000 * 1000)
#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL 0
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL

#define EXAMPLE_PIN_NUM_SCLK 18
#define EXAMPLE_PIN_NUM_MOSI 23
#define EXAMPLE_PIN_NUM_MISO -1
#define EXAMPLE_PIN_NUM_LCD_DC 2
#define EXAMPLE_PIN_NUM_LCD_RST 4 //-1
#define EXAMPLE_PIN_NUM_LCD_CS 5
#define EXAMPLE_PIN_NUM_BK_LIGHT 12
#define EXAMPLE_PIN_NUM_TOUCH_CS -1

// 分辨率定义和命令位宽
#if CONFIG_EXAMPLE_LCD_CONTROLLER_ILI9341
#define EXAMPLE_LCD_H_RES 240
#define EXAMPLE_LCD_V_RES 320
#elif CONFIG_EXAMPLE_LCD_CONTROLLER_GC9A01
#define EXAMPLE_LCD_H_RES 240
#define EXAMPLE_LCD_V_RES 240
#elif CONFIG_EXAMPLE_LCD_CONTROLLER_ST7789
#define EXAMPLE_LCD_H_RES 240 // 320
#define EXAMPLE_LCD_V_RES 240
#endif
#define EXAMPLE_LCD_CMD_BITS 8
#define EXAMPLE_LCD_PARAM_BITS 8
#define EXAMPLE_LVGL_TICK_PERIOD_MS 2

#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
esp_lcd_touch_handle_t tp = NULL;
#endif

#if CONFIG_EXAMPLE_LCD_KEYBOARD_ENABLED
#include "bsp_key.h"
#include "bsp_buzzer.h"
#endif

extern void example_lvgl_demo_ui(lv_disp_t *disp);

// ========================== LVGL 刷新与回调函数 ==========================
// 作用：LVGL 刷新屏幕时调用，将缓冲区内容写入 LCD
// 顺序：注册 LVGL 显示驱动时设置

// 刷新完成通知 LVGL
static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
    return false;
}

// LVGL 刷新回调，将缓冲区内容写入屏幕
static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)drv->user_data;
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;
    // 拷贝缓冲区内容到屏幕指定区域
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
}

// 屏幕旋转时的驱动参数更新回调
static void example_lvgl_port_update_callback(lv_disp_drv_t *drv)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)drv->user_data;

    switch (drv->rotated)
    {
    case LV_DISP_ROT_270:
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, false, false);
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
        esp_lcd_touch_set_mirror_y(tp, true);
        esp_lcd_touch_set_mirror_x(tp, false);
#endif
        break;
    case LV_DISP_ROT_NONE:
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, false, true);
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
        esp_lcd_touch_set_mirror_y(tp, true);
        esp_lcd_touch_set_mirror_x(tp, false);
#endif
        break;
    case LV_DISP_ROT_90:
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, true, true);
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
        esp_lcd_touch_set_mirror_y(tp, true);
        esp_lcd_touch_set_mirror_x(tp, false);
#endif
        break;
    case LV_DISP_ROT_180:
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, true, false);
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
        esp_lcd_touch_set_mirror_y(tp, true);
        esp_lcd_touch_set_mirror_x(tp, false);
#endif
        break;
    }
}

// ========================== LVGL 回调函数 ==========================
/*
 * 板块 3：触摸屏回调
 * 作用：处理触摸屏输入和数据读取
 */
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
// 触摸屏读取回调，获取触摸点坐标
static void example_lvgl_touch_cb(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    uint16_t touchpad_x[1] = {0};
    uint16_t touchpad_y[1] = {0};
    uint8_t touchpad_cnt = 0;

    // 读取触摸控制器数据
    esp_lcd_touch_read_data(drv->user_data);

    // 获取坐标
    bool touchpad_pressed = esp_lcd_touch_get_coordinates(drv->user_data, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

    if (touchpad_pressed && touchpad_cnt > 0)
    {
        data->point.x = touchpad_x[0];
        data->point.y = touchpad_y[0];
        data->state = LV_INDEV_STATE_PRESSED;
    }
    else
    {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}
#endif

/*
 * 板块 3：键盘输入回调
 * 作用：处理键盘输入后执行的逻辑
 */

#ifdef CONFIG_EXAMPLE_LCD_KEYBOARD_ENABLED
void example_lvgl_keyboard_read_cb(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    static uint32_t last_key = 0;
    uint32_t act_key = 0;
    act_key = bind_key_read(groups.group_main);
    // act_key = keypad_get_key();
    if (act_key != 0) // 有按键按下
    {
        bsp_buzzer_beep(100); // 按键按下时蜂鸣器响一下

        data->state = LV_INDEV_STATE_PR;
        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch (act_key)
        {
        case 1:
            act_key = LV_KEY_NEXT; // 切换控件焦点
            break;
        case 2:
            act_key = LV_KEY_PREV;// 切换控件焦点
            break;
        case 3:
            act_key = LV_KEY_LEFT; // 修改控件参数值
            break;
        case 4:
            act_key = LV_KEY_RIGHT;// 修改控件参数值
            break;
        case 5:
            act_key = LV_KEY_ENTER; // 执行控件操作
            break;
        }

        // 发送按键编号给last_key
        last_key = act_key;
    }
    else // 无按键按下
    {
        data->state = LV_INDEV_STATE_REL; // 按键释放(Button Release)
    }
    data->key = last_key;
}
#endif // CONFIG_EXAMPLE_LCD_KEYBOARD_ENABLED

/*
 * 板块 3：LVGL 定时器回调
 * 作用：定时递增 LVGL tick，用于 LVGL 内部时间管理
 */

// LVGL 定时器回调，定时递增 LVGL tick
static void example_increase_lvgl_tick(void *arg)
{
    lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}

// ========================== 应用初始化主流程 ==========================
// 作用：初始化 I2C、SPI、LCD、背光、LVGL、触摸等，注册 LVGL 驱动
// 顺序：系统启动后调用，完成所有底层和 LVGL 初始化
void app_init(void)
{
    // 1. 初始化 I2C（如有外设）
    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    static lv_disp_draw_buf_t disp_buf; // LVGL 显存缓冲区
    static lv_disp_drv_t disp_drv;      // LVGL 显示驱动结构体

    // 2. 配置背光 GPIO 并关闭背光
    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << EXAMPLE_PIN_NUM_BK_LIGHT};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    // 3. 初始化 SPI 总线
    ESP_LOGI(TAG, "Initialize SPI bus");
    spi_bus_config_t buscfg = {
        .sclk_io_num = EXAMPLE_PIN_NUM_SCLK,
        .mosi_io_num = EXAMPLE_PIN_NUM_MOSI,
        .miso_io_num = EXAMPLE_PIN_NUM_MISO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = EXAMPLE_LCD_H_RES * 80 * sizeof(uint16_t),
    };
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));

    // 4. 安装 LCD IO 驱动
    ESP_LOGI(TAG, "Install panel IO");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = EXAMPLE_PIN_NUM_LCD_DC,
        .cs_gpio_num = EXAMPLE_PIN_NUM_LCD_CS,
        .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
        .lcd_cmd_bits = EXAMPLE_LCD_CMD_BITS,
        .lcd_param_bits = EXAMPLE_LCD_PARAM_BITS,
        .spi_mode = 0,
        .trans_queue_depth = 10,
        .on_color_trans_done = example_notify_lvgl_flush_ready,
        .user_ctx = &disp_drv,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));

    // 5. 安装 LCD 屏幕驱动
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_RGB,
        .bits_per_pixel = 16,
    };
#if CONFIG_EXAMPLE_LCD_CONTROLLER_ILI9341
    ESP_LOGI(TAG, "Install ILI9341 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_ili9341(io_handle, &panel_config, &panel_handle));
#elif CONFIG_EXAMPLE_LCD_CONTROLLER_GC9A01
    ESP_LOGI(TAG, "Install GC9A01 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_gc9a01(io_handle, &panel_config, &panel_handle));
#elif CONFIG_EXAMPLE_LCD_CONTROLLER_ST7789
    ESP_LOGI(TAG, "Install ST7789 panel driver");
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));
#endif

    // 6. 初始化 LCD 屏幕参数
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
#if CONFIG_EXAMPLE_LCD_CONTROLLER_GC9A01
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
#endif
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, false, true));
    ESP_ERROR_CHECK(esp_lcd_panel_invert_color(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
    // 7. 初始化触摸屏（如有）
    esp_lcd_panel_io_handle_t tp_io_handle = NULL;
    esp_lcd_panel_io_i2c_config_t tp_io_config = ESP_LCD_TOUCH_IO_I2C_FT5x06_CONFIG();

    esp_lcd_touch_config_t tp_cfg = {
        .x_max = EXAMPLE_LCD_V_RES,
        .y_max = EXAMPLE_LCD_H_RES,
        .rst_gpio_num = -1,
        .int_gpio_num = -1,
        .flags = {
            .swap_xy = 1,
            .mirror_x = 0,
            .mirror_y = 1,
        },
    };

#if CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_STMPE610
    ESP_LOGI(TAG, "Initialize touch controller STMPE610");
    ESP_ERROR_CHECK(esp_lcd_touch_new_spi_stmpe610(tp_io_handle, &tp_cfg, &tp));
#endif // CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_STMPE610
#if CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_FT6336
    ESP_LOGI(TAG, "Initialize touch controller FT6336");
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_ft5x06(tp_io_handle, &tp_cfg, &tp));
#endif // CONFIG_EXAMPLE_LCD_TOUCH_CONTROLLER_FT6336
#endif // CONFIG_EXAMPLE_LCD_TOUCH_ENABLED

    // 8. 打开背光
    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_LCD_BK_LIGHT_ON_LEVEL);

    // 9. 初始化 LVGL 库
    ESP_LOGI(TAG, "Initialize LVGL library");
    lv_init();

    // 10. 分配 LVGL 显存缓冲区
    lv_color_t *buf1 = heap_caps_malloc(EXAMPLE_LCD_H_RES * 20 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1);
    lv_color_t *buf2 = heap_caps_malloc(EXAMPLE_LCD_H_RES * 20 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2);
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, EXAMPLE_LCD_H_RES * 20);

    // 11. 注册 LVGL 显示驱动
    ESP_LOGI(TAG, "Register display driver to LVGL");
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    disp_drv.ver_res = EXAMPLE_LCD_V_RES;
    disp_drv.flush_cb = example_lvgl_flush_cb;
    disp_drv.drv_update_cb = example_lvgl_port_update_callback;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = panel_handle;

    /* TODO : 解决屏幕偏移问题 */
    // disp_drv.offset_x = 80;
    // disp_drv.offset_y = 10;

    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    // 12. 设置屏幕初始旋转（如有需要）
    lv_disp_set_rotation(lv_disp_get_default(), LV_DISP_ROT_270);

    // 13. 安装 LVGL tick 定时器（定时驱动 LVGL 内部时钟）
    ESP_LOGI(TAG, "Install LVGL tick timer");
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &example_increase_lvgl_tick,
        .name = "lvgl_tick"};
    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, EXAMPLE_LVGL_TICK_PERIOD_MS * 1000));

    /* 14. 注册 LVGL 外部输入驱动 */

    // 触摸输入类型
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.disp = disp;
    indev_drv.read_cb = example_lvgl_touch_cb;
    indev_drv.user_data = tp;
    lv_indev_drv_register(&indev_drv);
#endif

    // 按键输入类型
#if CONFIG_EXAMPLE_LCD_KEYBOARD_ENABLED

    bsp_key_init();
    bsp_buzzer_init();

    // 15. 注册 LVGL 键盘输入驱动（如有）
    lv_indev_t *indev_keypad;
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = example_lvgl_keyboard_read_cb; // 需要实现键盘读取回调
    indev_drv.user_data = NULL;                        // 可选参数
    indev_keypad = lv_indev_drv_register(&indev_drv);


    // call this before "ui_init()"
    ui_create_groups();
    // set group for your input device
    lv_indev_set_group(indev_keypad, groups.group_main);
    ui_init();

#endif // CONFIG_EXAMPLE_LCD_KEYBOARD_ENABLED
}
