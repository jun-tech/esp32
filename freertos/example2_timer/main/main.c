#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 简单任务
 */
void task(TimerHandle_t xTimer)
{
    const char *timerName = pcTimerGetName(xTimer);
    ESP_LOGI("task", "Call method: %s", timerName);
}

void app_main(void)
{
    TimerHandle_t xTimer, xTimer2;
    xTimer = xTimerCreate("task1", pdMS_TO_TICKS(1000), pdTRUE /*pdFALSE*/, (void *)1, task);
    xTimer2 = xTimerCreate("task2", pdMS_TO_TICKS(2000), pdTRUE /*pdFALSE*/, (void *)1, task);

    xTimerStart(xTimer, 0);
    xTimerStart(xTimer2, 0);
}
