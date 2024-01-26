#include <esp_err.h>
#include <esp_log.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_freertos_hooks.h"
#include "bsp_spi.h"

#include "lv_port_disp.h"
#include "lv_port_tick.h"
#include "lv_port_touch.h"

#include "lv_demos.h"

void app_main(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(10);

    // spi总线
    bsp_spi_bus_init(HSPI_HOST, 12 /* miso */, 13 /* mosi */, 14 /*sck*/);

    // lvgl 初始化
    lv_init();
    lv_port_disp_init();
    lv_port_touch_init(HSPI_HOST);
    lv_create_tick();

    // 演示
    lv_demo_widgets();
    // lv_demo_music();
    // lv_demo_benchmark();
    // lv_demo_stress();

    while (1)
    {
        lv_timer_handler();
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}
