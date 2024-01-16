/* SPI Master example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_freertos_hooks.h"

// lvgl
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_demos.h"

#include "spi_mgr.h"
#include "tft_drivers.h"

static const char *TAG = "MAIN";

// 屏幕设备
TFTDev_t tftDev = {
    // 设备总线
    .devspi = {
        .spi_host = VSPI_HOST,
        .pin_dc = 27,
        .pin_mosi = 13,
        .pin_miso = -1,
        .pin_sclk = 14,
        .pin_cs = 15},
    .width = TFT_WIDTH,
    .height = TFT_HEIGHT,
    .model = 0x7796,
    .offsetx = 0,
    .offsety = 0,
    .direction = DIRECTION0,
    .pincs = 15,
    .pinrst = 33,
    .pinbckl = 32};

/*-----------------函数声明-----------------------------------*/
void lvgl_bg_color_test(void);
/*-----------------函数声明-----------------------------------*/

/* LVGL 移植部分 */
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(portTICK_PERIOD_MS);
}
SemaphoreHandle_t xGuiSemaphore;

void lvgl_bg_color_test(void)
{
    // base bg color
    static lv_style_t style;
    lv_style_init(&style);
    // lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_RED, 1));// 颜色纯度
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_RED)); // 单色

    lv_obj_t *obj = lv_obj_create(lv_scr_act()); // 创建对象
    lv_obj_add_style(obj, &style, 0);            // 设置对象的样式
    lv_obj_set_size(obj, tftDev.width / 3, tftDev.height);
    lv_obj_set_pos(obj, 0, 0);

    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());                          // 创建对象
    lv_obj_add_style(obj1, &style, 0);                                     // 设置对象的样式
    lv_obj_set_style_bg_color(obj1, lv_palette_main(LV_PALETTE_GREEN), 0); // 单色
    lv_obj_set_size(obj1, tftDev.width / 3, tftDev.height);
    lv_obj_set_pos(obj1, tftDev.width / 3, 0);

    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());                         // 创建对象
    lv_obj_add_style(obj2, &style, 0);                                    // 设置对象的样式
    lv_obj_set_style_bg_color(obj2, lv_palette_main(LV_PALETTE_BLUE), 0); // 单色
    lv_obj_set_size(obj2, tftDev.width / 3, tftDev.height);
    lv_obj_set_pos(obj2, (tftDev.width / 3) * 2, 0);
}

static void gui_demo()
{
    // 开启sdcard
    // lvgl_read_sdcard_dir_test();
    // lvgl_read_sdcard_test();
    // lvgl_bg_color_test();
    // lvgl_test();
    lv_demo_widgets();
    // lv_demo_keypad_encoder();
    // lv_demo_music();
    // lv_demo_printer();
    // 以下2案例性能测试
    // lv_demo_benchmark();
    // lv_demo_stress();
}

/* UI 任务 */
static void gui_task(void *arg)
{
    xGuiSemaphore = xSemaphoreCreateMutex();
    // 集成lvgl
    lv_init();
    lv_port_disp_init();

    esp_register_freertos_tick_hook((void *)lv_tick_task);

    gui_demo();
    ESP_LOGI("main", "begin timer");
    // lv_tm = lv_timer_create(lv_tm_cb, 3000, 0);

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

void app_main()
{
    // 设备总线注册
    spi_mgr_bus_init(&tftDev.devspi);

    // 将屏幕添加到总线80MHz
    spi_mgr_bus_add_device(&tftDev.devspi, 80 * 1000 * 1000);

    // 屏幕初始化
    tftInit(&tftDev);

    // 设置背光
    tftSetBackLight(&tftDev, 20);

    // 屏幕方向
    tftSetDirection(&tftDev, DIRECTION90);

    // 清屏
    tftClear(&tftDev, RED);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    tftClear(&tftDev, GREEN);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    tftClear(&tftDev, BLUE);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    ESP_LOGI(TAG, "lvgl start...");

    // xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 20, NULL, 1, NULL, 0);
    xTaskCreate(gui_task, "gui task", 1024 * 20, NULL, 1, NULL);
}