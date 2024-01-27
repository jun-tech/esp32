#include <stdio.h>
#include "bsp_xpt2046.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "bsp_spi.h"

void app_main(void)
{
    // spi总线
    bsp_spi_bus_init(HSPI_HOST, 12 /* miso */, 13 /* mosi */, 14 /*sck*/);
    // 触摸屏初始化
    xpt2046_init(HSPI_HOST, 27 /*cs*/, 26 /*pen*/);
    // xpt2046_init(HSPI_HOST, 21 /*cs*/, 22 /*pen*/);

    while (1)
    {
        xpt2046_read();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
