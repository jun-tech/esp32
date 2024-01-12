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
#include "esp_system.h"
// #include "driver/spi_master.h"
// #include "driver/gpio.h"
#include "esp_log.h"

// #include "lvgl_drivers.h"

// lvgl
// #include "lvgl.h"
// // #include "lv_port_disp.h"
// #include "lv_demos.h"

#include "spi_mgr.h"
#include "tft_drivers.h"

static const char *TAG = "MAIN";

void app_main()
{
    // 设备总线注册
    DevSPI_t devspi = {
        .spi_host = VSPI_HOST,
        .pin_dc = 27,
        .pin_mosi = 13,
        .pin_miso = -1,
        .pin_sclk = 14,
        .pin_cs = 15};
    spi_mgr_bus_init(&devspi);

    // 屏幕设备
    TFTDev_t tftDev = {
        .devspi = devspi,
        .width = 320,
        .height = 480,
        .model = 0x7796,
        .offsetx = 0,
        .offsety = 0,
        .pincs = 15,
        .pinrst = 33,
        .pinbckl = 32};
    // 将屏幕添加到总线80MHz
    spi_mgr_bus_add_device(&tftDev.devspi, 80 * 1000 * 1000, 15);

    // 屏幕初始化
    tftInit(&tftDev);

    // 清屏
    while (1)
    {
        tftClear(&tftDev, RED);
        vTaskDelay(100 / portTICK_PERIOD_MS);

        tftClear(&tftDev, GREEN);
        vTaskDelay(100 / portTICK_PERIOD_MS);

        tftClear(&tftDev, BLUE);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}