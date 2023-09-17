#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * mailbox 相当于广播
 */

/**
 * 发送队列
 */
void sendQueue(void *pvParam)
{
    QueueHandle_t MailBox = (QueueHandle_t)pvParam;
    int i = 0;
    while (1)
    {
        BaseType_t flag = xQueueOverwrite(MailBox, (void *)&i);
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
    QueueSetHandle_t MailBox = (QueueSetHandle_t)pvParam;
    while (1)
    {
        int i;
        // xQueuePeek只读不对队列元素移除
        BaseType_t flag = xQueuePeek(MailBox, &i, portMAX_DELAY);
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
    QueueHandle_t MailBox;
    // 只建一个
    MailBox = xQueueCreate(1, sizeof(int));

    if (MailBox != NULL)
    {
        ESP_LOGI("main", "create queue mailbox successfull! ");
        xTaskCreate(sendQueue, "sendQueue", 1024 * 5, (void *)MailBox, 1, NULL);
        xTaskCreate(reciveQueue, "reciveQueue", 1024 * 5, (void *)MailBox, 1, NULL);
        xTaskCreate(reciveQueue, "reciveQueue2", 1024 * 5, (void *)MailBox, 1, NULL);
        xTaskCreate(reciveQueue, "reciveQueue3", 1024 * 5, (void *)MailBox, 1, NULL);
    }
    else
    {
        ESP_LOGE("main", "create queue fail! ");
    }
}
