#include <esp_err.h>
#include <esp_log.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "lv_port_disp.h"
#include "lv_port_tick.h"

#include "lv_demos.h"

void app_main(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(10);

    lv_init();
    lv_port_disp_init();
    lv_create_tick();

    lv_demo_music();
    // lv_demo_benchmark();
    // lv_demo_stress();

    while (1)
    {
        lv_task_handler();
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}
