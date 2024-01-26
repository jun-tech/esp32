/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_freertos_hooks.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_log.h"
#include "lvgl.h"
#include "lv_demos.h"

static const char *TAG = "example";

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////// Please update the following configuration according to your LCD spec //////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 实测最大13Mhz
#define EXAMPLE_LCD_PIXEL_CLOCK_HZ (13 * 1000 * 1000)

#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL 1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL
#define EXAMPLE_PIN_NUM_DATA0 5
#define EXAMPLE_PIN_NUM_DATA1 18
#define EXAMPLE_PIN_NUM_DATA2 19
#define EXAMPLE_PIN_NUM_DATA3 21
#define EXAMPLE_PIN_NUM_DATA4 3
#define EXAMPLE_PIN_NUM_DATA5 1
#define EXAMPLE_PIN_NUM_DATA6 22
#define EXAMPLE_PIN_NUM_DATA7 23
#define EXAMPLE_PIN_NUM_DATA8 13
#define EXAMPLE_PIN_NUM_DATA9 12
#define EXAMPLE_PIN_NUM_DATA10 14
#define EXAMPLE_PIN_NUM_DATA11 27
#define EXAMPLE_PIN_NUM_DATA12 26
#define EXAMPLE_PIN_NUM_DATA13 25
#define EXAMPLE_PIN_NUM_DATA14 33
#define EXAMPLE_PIN_NUM_DATA15 32
#define EXAMPLE_PIN_NUM_PCLK 16 /* WR 引脚*/
// #define EXAMPLE_PIN_NUM_RD 4    /* RD 引脚*/
#define EXAMPLE_PIN_NUM_CS 2
#define EXAMPLE_PIN_NUM_DC 15 /* RS 引脚*/
#define EXAMPLE_PIN_NUM_RST 17
#define EXAMPLE_PIN_NUM_BK_LIGHT 4 /* 接3v3*/

// The pixel number in horizontal and vertical
#define EXAMPLE_LCD_H_RES 320
#define EXAMPLE_LCD_V_RES 480
#define LVGL_DISP_BUF_SIZE EXAMPLE_LCD_H_RES *EXAMPLE_LCD_V_RES / 10

#define EXAMPLE_LVGL_TICK_PERIOD_MS 2

// Supported alignment: 16, 32, 64. A higher alignment can enables higher burst transfer size, thus a higher i80 bus throughput.
#define EXAMPLE_PSRAM_DATA_ALIGNMENT 64

extern void example_lvgl_demo_ui(lv_disp_t *disp);

static bool example_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
    return false;
}

static void example_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)drv->user_data;
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;
    // copy a buffer's content to a specific area of the display
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
}

/* LVGL 移植部分 */
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(portTICK_PERIOD_MS);
}
SemaphoreHandle_t xGuiSemaphore;

static void gui_demo()
{
    // 开启sdcard
    // lvgl_bg_color_test();
    // lv_demo_widgets();
    // lv_demo_keypad_encoder();
    lv_demo_music();
    // lv_demo_printer();
    // 以下2案例性能测试
    // lv_demo_benchmark();
    // lv_demo_stress();
}

/* UI 任务 */
static void gui_task(void *arg)
{
    xGuiSemaphore = xSemaphoreCreateMutex();

    static lv_disp_draw_buf_t disp_buf; // contains internal graphic buffer(s) called draw buffer(s)
    static lv_disp_drv_t disp_drv;      // contains callback functions

    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << EXAMPLE_PIN_NUM_BK_LIGHT};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));
    gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL);

    ESP_LOGI(TAG, "Initialize Intel 8080 bus");
    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .dc_gpio_num = EXAMPLE_PIN_NUM_DC,
        .wr_gpio_num = EXAMPLE_PIN_NUM_PCLK,
        .data_gpio_nums = {
            EXAMPLE_PIN_NUM_DATA0,
            EXAMPLE_PIN_NUM_DATA1,
            EXAMPLE_PIN_NUM_DATA2,
            EXAMPLE_PIN_NUM_DATA3,
            EXAMPLE_PIN_NUM_DATA4,
            EXAMPLE_PIN_NUM_DATA5,
            EXAMPLE_PIN_NUM_DATA6,
            EXAMPLE_PIN_NUM_DATA7,
            // EXAMPLE_PIN_NUM_DATA8,
            // EXAMPLE_PIN_NUM_DATA9,
            // EXAMPLE_PIN_NUM_DATA10,
            // EXAMPLE_PIN_NUM_DATA11,
            // EXAMPLE_PIN_NUM_DATA12,
            // EXAMPLE_PIN_NUM_DATA13,
            // EXAMPLE_PIN_NUM_DATA14,
            // EXAMPLE_PIN_NUM_DATA15,
        },
        .bus_width = 8, // 并口8位16位
        .max_transfer_bytes = LVGL_DISP_BUF_SIZE * sizeof(uint16_t),
        .psram_trans_align = EXAMPLE_PSRAM_DATA_ALIGNMENT,
        .sram_trans_align = 4,
    };
    ESP_ERROR_CHECK(esp_lcd_new_i80_bus(&bus_config, &i80_bus));
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = EXAMPLE_PIN_NUM_CS,
        .pclk_hz = EXAMPLE_LCD_PIXEL_CLOCK_HZ,
        .trans_queue_depth = 10,
        .dc_levels = {
            .dc_idle_level = 0,
            .dc_cmd_level = 0,
            .dc_dummy_level = 0,
            .dc_data_level = 1,
        },
        // .flags = {
        //     .swap_color_bytes = !LV_COLOR_16_SWAP, // Swap can be done in LvGL (default) or DMA
        // },
        .on_color_trans_done = example_notify_lvgl_flush_ready,
        .user_ctx = &disp_drv,
        .lcd_cmd_bits = 8,
        .lcd_param_bits = 8,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle));

    ESP_LOGI(TAG, "Install LCD driver of st7796");
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
        .bits_per_pixel = 16,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));

    esp_lcd_panel_reset(panel_handle);
    esp_lcd_panel_init(panel_handle);
    // Set inversion, x/y coordinate order, x/y mirror according to your LCD module spec
    // the gap is LCD panel specific, even panels with the same driver IC, can have different gap value
    esp_lcd_panel_swap_xy(panel_handle, true);
    esp_lcd_panel_invert_color(panel_handle, false);

    // 初始化屏幕
    esp_lcd_panel_io_tx_param(io_handle, 0x01, NULL, 0); //  Software reset
    vTaskDelay(pdMS_TO_TICKS(100));
    esp_lcd_panel_io_tx_param(io_handle, 0x11, NULL, 0); // 退出休眠模式
    vTaskDelay(pdMS_TO_TICKS(100));
    // esp_lcd_panel_io_tx_param(io_handle, 0x21, NULL, 0); // 开启反色显示
    //    vTaskDelay(pdMS_TO_TICKS(100));
    esp_lcd_panel_io_tx_param(io_handle, 0xF0, (uint8_t[]){0xC3}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0xF0, (uint8_t[]){0x96}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0x36, (uint8_t[]){0x48}, 1); // 显存访问方式: MY=0, MX=1, MV=0, ML=0, RGB=1, MH=0
    esp_lcd_panel_io_tx_param(io_handle, 0x3A, (uint8_t[]){0x55}, 1); // 像素颜色格式: RGB模式16位, MCU模式16位
    esp_lcd_panel_io_tx_param(io_handle, 0xB4, (uint8_t[]){0x01}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0xB6, (uint8_t[]){0x80, 0x02, 0x3B}, 3);
    esp_lcd_panel_io_tx_param(io_handle, 0xE8, (uint8_t[]){0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33}, 8);
    esp_lcd_panel_io_tx_param(io_handle, 0xC1, (uint8_t[]){0x06}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0xC2, (uint8_t[]){0xA7}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0xC5, (uint8_t[]){0x18}, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    esp_lcd_panel_io_tx_param(io_handle, 0xE0, (uint8_t[]){0xF0, 0x09, 0x0b, 0x06, 0x04, 0x15, 0x2F, 0x54, 0x42, 0x3C, 0x17, 0x14, 0x18, 0x1B}, 14);
    esp_lcd_panel_io_tx_param(io_handle, 0xE1, (uint8_t[]){0xE0, 0x09, 0x0B, 0x06, 0x04, 0x03, 0x2B, 0x43, 0x42, 0x3B, 0x16, 0x14, 0x17, 0x1B}, 14);
    vTaskDelay(pdMS_TO_TICKS(100));
    esp_lcd_panel_io_tx_param(io_handle, 0xF0, (uint8_t[]){0x3C}, 1);
    esp_lcd_panel_io_tx_param(io_handle, 0xF0, (uint8_t[]){0x69}, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    esp_lcd_panel_io_tx_param(io_handle, 0x29, NULL, 0); // display on
    vTaskDelay(pdMS_TO_TICKS(100));

    // user can flush pre-defined pattern to the screen before we turn on the screen or backlight
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_LCD_BK_LIGHT_ON_LEVEL);

    ESP_LOGI(TAG, "Initialize LVGL library");
    lv_init();
    // alloc draw buffers used by LVGL
    // it's recommended to choose the size of the draw buffer(s) to be at least 1/10 screen sized
    lv_color_t *buf1 = NULL;
    lv_color_t *buf2 = NULL;
    buf1 = heap_caps_malloc(LVGL_DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
    buf2 = heap_caps_malloc(LVGL_DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
    assert(buf1 != NULL);
    assert(buf2 != NULL);
    // initialize LVGL draw buffers
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, LVGL_DISP_BUF_SIZE);

    ESP_LOGI(TAG, "Register display driver to LVGL");
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    disp_drv.ver_res = EXAMPLE_LCD_V_RES;
    disp_drv.flush_cb = example_lvgl_flush_cb;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = panel_handle;
    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    esp_register_freertos_tick_hook((void *)lv_tick_task);

    gui_demo();
    // example_lvgl_demo_ui(disp);

    while (1)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            lv_timer_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    vTaskDelete(NULL);
}

void app_main(void)
{
    xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 6, NULL, 1, NULL, 0);
}