#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 二进制信号量，多个task并发操作时，确保线程安全
 */

// 二进制信号量
SemaphoreHandle_t semaphoreLock;
// 假设多个任务对变量进行处理
int i = 0;

void task1(void *pvParam)
{
    while (1)
    {
        xSemaphoreTake(semaphoreLock, portMAX_DELAY);
        // 模拟对i递增（task独占）
        for (i = 0; i < 10; i++)
        {
            ESP_LOGI("task1", "Call method: %d", i);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        xSemaphoreGive(semaphoreLock);
        // delay下，让其他task调度
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}

void task2(void *pvParam)
{
    while (1)
    {
        xSemaphoreTake(semaphoreLock, portMAX_DELAY);
        // 模拟对i递增（task独占）
        for (i = 0; i < 10; i++)
        {
            ESP_LOGI("task2", "Call method: %d", i);
            vTaskDelay(pdMS_TO_TICKS(500));
        }
        xSemaphoreGive(semaphoreLock);
        // delay下，让其他task调度
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    // 创建信号量
    semaphoreLock = xSemaphoreCreateBinary();
    xSemaphoreGive(semaphoreLock);
    // 下面模拟2个任务对i执行竞争操作，查看i是否按任务先后加1递增处理（没加信号量，多个任务会同时对i递增处理）
    xTaskCreatePinnedToCore(task1, "task1", 1024 * 5, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(task2, "task2", 1024 * 5, NULL, 1, NULL, 1);
}
