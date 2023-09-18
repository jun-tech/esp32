#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 事件组同步bits，模拟异步发送并接收3bits数据。3bits数据接收完毕后，重新下一次
 */

#define FIRST_TASK_BIT (1 << 0)  /* Event bit 0, set by the first task. */
#define SECOND_TASK_BIT (1 << 1) /* Event bit 1, set by the second task. */
#define THIRD_TASK_BIT (1 << 2)  /* Event bit 2, set by the third task. */

EventGroupHandle_t xEventGroup;

// 接收数据
void recive_data(void *pvParam)
{
    EventBits_t uxBits;
    // 所有位接收
    const EventBits_t uxAllSyncBits = (FIRST_TASK_BIT |
                                       SECOND_TASK_BIT |
                                       THIRD_TASK_BIT);
    // 发送过来的bits
    EventBits_t uxThisTasksSyncBit = (EventBits_t)pvParam;
    while (1)
    {
        /* Wait for all the tasks to have reached their respective synchronization points. */
        xEventGroupSync(/* The event group used to synchronize. */
                        xEventGroup,
                        /* The bit set by this task to indicate it has reached the
                        synchronization point. */
                        uxThisTasksSyncBit,
                        /* The bits to wait for, one bit for each task taking part
                        in the synchronization. */
                        uxAllSyncBits,
                        /* Wait indefinitely for all three tasks to reach the
                        synchronization point. */
                        portMAX_DELAY);

        ESP_LOGW(pcTaskGetTaskName(NULL), "exited sync point");

        vTaskDelay(pdMS_TO_TICKS(500));
    }
    vTaskDelete(NULL);
}

// 发送bit1
void first_task_bit(void *pvParam)
{
    EventBits_t uxBits;
    while (1)
    {
        xEventGroupSetBits(xEventGroup, FIRST_TASK_BIT);
        ESP_LOGI(pcTaskGetTaskName(NULL), "first task bit send! ");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

// 发送bit2
void second_task_bit(void *pvParam)
{
    EventBits_t uxBits;
    while (1)
    {
        xEventGroupSetBits(xEventGroup, SECOND_TASK_BIT);
        ESP_LOGI(pcTaskGetTaskName(NULL), "second task bit send! ");
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
    vTaskDelete(NULL);
}

// 发送bit3
void third_task_bit(void *pvParam)
{
    EventBits_t uxBits;
    while (1)
    {
        xEventGroupSetBits(xEventGroup, THIRD_TASK_BIT);
        ESP_LOGI(pcTaskGetTaskName(NULL), "third task bit send! ");
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    xEventGroup = xEventGroupCreate();
    vTaskSuspendAll();
    xTaskCreate(recive_data, "recive_data", 1024 * 5, NULL, 4, NULL);
    xTaskCreate(first_task_bit, "first_task_bit", 1024 * 5, FIRST_TASK_BIT, 1, NULL);
    xTaskCreate(second_task_bit, "second_task_bit", 1024 * 5, SECOND_TASK_BIT, 2, NULL);
    xTaskCreate(third_task_bit, "third_task_bit", 1024 * 5, THIRD_TASK_BIT, 3, NULL);
    xTaskResumeAll();
}
