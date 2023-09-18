#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 递归锁
 */
SemaphoreHandle_t semaphoreRecursive;

void task1(void *pvParam)
{
    while (1)
    {
        xSemaphoreTakeRecursive(semaphoreRecursive, portMAX_DELAY);
        // 获取1次锁
        ESP_LOGI("task1", "task1 get lock 1");
        for (int i = 0; i < 10; i++)
        {
            ESP_LOGI("task1", "task1 take %d", i);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }

        // 获取2次锁，2秒后释放2锁
        xSemaphoreTakeRecursive(semaphoreRecursive, portMAX_DELAY);
        ESP_LOGI("task1", "task1 get lock 2");
        vTaskDelay(pdMS_TO_TICKS(2000));
        ESP_LOGI("task1", "task1 give lock 2");
        xSemaphoreGiveRecursive(semaphoreRecursive);

        // 1秒后释放1锁（递归释放上一级锁）
        vTaskDelay(pdMS_TO_TICKS(1000));
        ESP_LOGI("task1", "task1 give lock 1");
        xSemaphoreGiveRecursive(semaphoreRecursive);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void task2(void *pvParam)
{
    while (1)
    {
        xSemaphoreTakeRecursive(semaphoreRecursive, portMAX_DELAY);
        ESP_LOGI("task2", "task1 get lock 1");
        for (int i = 0; i < 10; i++)
        {
            ESP_LOGI("task2", "task2 take %d", i);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
        ESP_LOGI("task2", "task2 give lock 1");
        xSemaphoreGiveRecursive(semaphoreRecursive);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    semaphoreRecursive = xSemaphoreCreateRecursiveMutex();
    if (semaphoreRecursive != NULL)
    {
        vTaskSuspendAll();
        xTaskCreate(task1, "task1", 1024 * 5, NULL, 3, NULL);
        xTaskCreate(task2, "task2", 1024 * 5, NULL, 3, NULL);
        xTaskResumeAll();
    }
}
