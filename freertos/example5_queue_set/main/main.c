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

void sendQueue2(void *pvParam)
{
    QueueHandle_t queueHandle = (QueueHandle_t)pvParam;
    int i = 0;
    while (1)
    {
        BaseType_t flag = xQueueSend(queueHandle, (void *)&i, 0);
        if (flag == pdPASS)
        {
            ESP_LOGI("sendQueue2", "send = %d ", i);
        }
        else if (flag == errQUEUE_FULL)
        {
            ESP_LOGE("sendQueue2", "queue full! ");
        }
        else
        {
            ESP_LOGE("sendQueue2", "send to queue fail! ");
        }
        i++;
        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

/**
 * 接收队列
 */
void reciveQueue(void *pvParam)
{
    QueueSetHandle_t queueSetHandle = (QueueSetHandle_t)pvParam;
    QueueSetMemberHandle_t queueData;
    while (1)
    {
        // 从队列集合中获取有数据的队列
        queueData = xQueueSelectFromSet(queueSetHandle, portMAX_DELAY);
        int i;
        BaseType_t flag = xQueueReceive(queueData, &i, portMAX_DELAY);
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

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void app_main(void)
{
    // 建立5，3队列
    QueueHandle_t queueHandle;
    queueHandle = xQueueCreate(5, sizeof(int));

    QueueHandle_t queueHandle2;
    queueHandle2 = xQueueCreate(3, sizeof(int));

    // 建立队列集，然后把队列添加到集
    QueueSetHandle_t QueueSetHandle;
    QueueSetHandle = xQueueCreateSet(8);

    xQueueAddToSet(queueHandle, QueueSetHandle);
    xQueueAddToSet(queueHandle2, QueueSetHandle);

    if (queueHandle != NULL && queueHandle2 != NULL && QueueSetHandle != NULL)
    {
        ESP_LOGI("main", "create queue & queue set successfull! ");
        xTaskCreate(sendQueue, "sendQueue", 1024 * 5, (void *)queueHandle, 1, NULL);
        xTaskCreate(sendQueue2, "sendQueue2", 1024 * 5, (void *)queueHandle2, 1, NULL);
        xTaskCreate(reciveQueue, "reciveQueue", 1024 * 5, (void *)QueueSetHandle, 1, NULL);
    }
    else
    {
        ESP_LOGE("main", "create queue fail! ");
    }
}
