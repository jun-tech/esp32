#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 发送队列
 */
void sendQueue(void *pvParam)
{
    QueueHandle_t queueHandle = (QueueHandle_t)pvParam;
    int i = 0;
    while (1)
    {
        BaseType_t flag = xQueueSend(queueHandle, (void *)&i, 0);
        if (flag == pdPASS)
        {
            ESP_LOGI("sendQueue", "send = %d ", i);
        }
        else if (flag == errQUEUE_FULL)
        {
            ESP_LOGE("sendQueue", "queue full! ");
        }
        else
        {
            ESP_LOGE("sendQueue", "send to queue fail! ");
        }
        i++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

/**
 * 接收队列
 */
void reciveQueue(void *pvParam)
{
    QueueHandle_t queueHandle = (QueueHandle_t)pvParam;
    while (1)
    {
        // 等待队列有数据
        if (uxQueueMessagesWaiting(queueHandle) != 0)
        {
            int i;
            // 等待时间换成uxQueueMessagesWaiting判断，队列有数据才读取
            BaseType_t flag = xQueueReceive(queueHandle, &i, 0 /*portMAX_DELAY*/);
            if (flag == pdPASS)
            {
                ESP_LOGI("reciveQueue", "recive = %d ", i);
            }
            else if (flag == errQUEUE_EMPTY)
            {
                ESP_LOGE("reciveQueue", "queue empty! ");
            }
            else
            {
                ESP_LOGE("reciveQueue", "recive from queue fail! ");
            }
        }

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void)
{
    QueueHandle_t queueHandle;
    // 初始化5个元素的队列
    queueHandle = xQueueCreate(5, sizeof(int));
    if (queueHandle != NULL)
    {
        ESP_LOGI("main", "create queue successfull! ");
        xTaskCreate(sendQueue, "sendQueue", 1024 * 5, (void *)queueHandle, 1, NULL);
        xTaskCreate(reciveQueue, "reciveQueue", 1024 * 5, (void *)queueHandle, 1, NULL);
    }
    else
    {
        ESP_LOGE("main", "create queue fail! ");
    }
}
