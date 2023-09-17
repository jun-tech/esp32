#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_task_wdt.h"

/**
 * 简单任务
 */
void task1(void *pvParam)
{
    esp_task_wdt_add(NULL);
    while (1)
    {
        ESP_LOGI("task", "Call method: %s", "task1");
        vTaskDelay(pdMS_TO_TICKS(1000));
        // 5秒内没喂狗，自动重启
        // 更改默认值时，可以在Component config > ESP System Settings > CONFIG_ESP_INT_WDT找到配置（Task Watchdog timeout period (seconds)）修改
        // 最久好像只可以设置10秒
        esp_task_wdt_reset();
    }
}

void app_main(void)
{
    TaskHandle_t xTask;
    xTaskCreate(task1, "task1", 1024 * 5, NULL, 1, &xTask);
}
