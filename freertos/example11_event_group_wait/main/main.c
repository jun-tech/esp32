#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 事件组等待bits
 * task1等待BIT_0或BIT_4满足条件设置后，触发事件组
 * task2对事件组BIT_0或BIT_4设值
 */

#define BIT_0 (1 << 0)
#define BIT_4 (1 << 4)

EventGroupHandle_t xEventGroup;

// 任务1等待满足条件的设置值
void task1(void *pvParam)
{
    EventBits_t uxBits;
    while (1)
    {
        /* Wait a maximum of 100ms for either bit 0 or bit 4 to be set within
            the event group. Clear the bits before exiting. */
        uxBits = xEventGroupWaitBits(
            xEventGroup,
            BIT_0 | BIT_4,  /* The bits within the event group to wait for. BIT1或BIT_4条件满足*/
            pdTRUE,         /* BIT_0 and BIT_4 should be cleared before returning. 运行前清除设置*/
            pdFALSE,        /* Don't wait for both bits, either bit will do. pdFALSE: BIT1或BIT_4条件满足, pdTRUE: BIT1且BIT_4条件满足*/
            portMAX_DELAY); /* Wait a maximum of 100ms for either bit to be set. */
        if ((uxBits & (BIT_0 | BIT_4)) == (BIT_0 | BIT_4))
        {
            /* xEventGroupWaitBits() returned because both bits were set. */
            ESP_LOGI("task1", "because both bits were set.");
        }
        else if ((uxBits & BIT_0) != 0)
        {
            /* xEventGroupWaitBits() returned because just BIT_0 was set. */
            ESP_LOGI("task1", "just BIT_0 was set. ");
        }
        else if ((uxBits & BIT_4) != 0)
        {
            /* xEventGroupWaitBits() returned because just BIT_4 was set. */
            ESP_LOGI("task1", "just BIT_4 was set. ");
        }
        else
        {
            /* xEventGroupWaitBits() returned because xTicksToWait ticks passed
            without either BIT_0 or BIT_4 becoming set. */
            ESP_LOGI("task1", "without either BIT_0 or BIT_4 becoming set.");
        }
    }
    vTaskDelete(NULL);
}

// 任务2负责设置值
void task2(void *pvParam)
{
    EventBits_t uxBits;
    while (1)
    {
        // BIT_0 设置
        uxBits = xEventGroupSetBits(xEventGroup, BIT_0);
        ESP_LOGI("task2", "BIT_0 was set. ");
        vTaskDelay(pdMS_TO_TICKS(1000));

        // BIT_4 设置
        uxBits = xEventGroupSetBits(xEventGroup, BIT_4);
        ESP_LOGI("task2", "BIT_4 was set. ");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    xEventGroup = xEventGroupCreate();
    vTaskSuspendAll();
    xTaskCreate(task1, "task1", 1024 * 5, NULL, 3, NULL);
    xTaskCreate(task2, "task2", 1024 * 5, NULL, 3, NULL);
    xTaskResumeAll();
}
