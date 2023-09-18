#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"

/**
    互斥型信号量必须是同一个任务申请，同一个任务释放，其他任务释放无效；
    二进制信号量和互斥量非常相似，但有一些细微差别：互斥量包括优先级继承机制，二进制信号量则不包含；
*/
SemaphoreHandle_t semaphoreMutex;

void task1(void *pvParam)
{
    while (1)
    {
        UBaseType_t flag = xSemaphoreTake(semaphoreMutex, portMAX_DELAY);
        if (flag == pdPASS)
        {
            for (int i = 0; i < 10; i++)
            {
                ESP_LOGI("task1", "task1 take %d", i);
                vTaskDelay(pdMS_TO_TICKS(1000));
            }
        }
        else
        {
            ESP_LOGW("task1", "task1 take fail");
        }
        xSemaphoreGive(semaphoreMutex);
        // delay下，让其他task调度
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void task2(void *pvParam)
{
    while (1)
    {
        UBaseType_t flag = xSemaphoreTake(semaphoreMutex, portMAX_DELAY);
        if (flag == pdPASS)
        {
            for (int i = 0; i < 10; i++)
            {
                ESP_LOGI("task2", "task2 take %d", i);
                vTaskDelay(pdMS_TO_TICKS(1000));
            }
        }
        else
        {
            ESP_LOGW("task2", "task2 take fail");
        }
        xSemaphoreGive(semaphoreMutex);
        // delay下，让其他task调度
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void task3(void *pvParam)
{
    while (1)
    {
        ;
    }
}

void app_main(void)
{
    // 二进制信号量，task3死循环导致idle无法执行，触发看门狗，整体任务崩溃无法执行
    // semaphoreMutex = xSemaphoreCreateBinary();
    // 互斥信号量，可以剥夺task3的时间片，进而执行其他任务
    semaphoreMutex = xSemaphoreCreateMutex();
    if (semaphoreMutex != NULL)
    {
        vTaskSuspendAll();
        xTaskCreate(task1, "task1", 1024 * 5, NULL, 3, NULL);
        xTaskCreate(task2, "task2", 1024 * 5, NULL, 3, NULL);
        xTaskCreate(task3, "task3", 1024 * 5, NULL, 2, NULL);
        xTaskResumeAll();
    }
}
