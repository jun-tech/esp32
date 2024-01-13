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
    .width = 320,
    .height = 480,
    .model = 0x7796,
    .offsetx = 0,
    .offsety = 0,
    .pincs = 15,
    .pinrst = 33,
    .pinbckl = 32};

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
    spi_mgr_bus_add_device(&tftDev.devspi, 20 * 1000 * 1000);

    // 屏幕初始化
    tftInit(&tftDev);

    // 清屏
    tftClear(&tftDev, RED);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    tftClear(&tftDev, GREEN);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    tftClear(&tftDev, BLUE);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    ESP_LOGI(TAG, "lvgl start...");

    xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 4, NULL, 1, NULL, 0);
}