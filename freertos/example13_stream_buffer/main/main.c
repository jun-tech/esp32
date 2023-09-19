#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/stream_buffer.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 消息缓存发送/接收
 * 缓冲区110，每条发送消息大概20，能收5条
 */

StreamBufferHandle_t streamBufferHandle;

// 接收数据
void recive_data(void *pvParam)
{
    // 5秒能收5条
    vTaskDelay(pdMS_TO_TICKS(5000));
    //  一次读取字节数
    char pvRxData[30];
    while (1)
    {
        // 清空上一次接收的消息
        memset(pvRxData, 0, sizeof(pvRxData));
        // 接收所有缓冲区数据
        size_t reciveBytes = xStreamBufferReceive(streamBufferHandle,
                                                  (void *)pvRxData,
                                                  sizeof(pvRxData),
                                                  portMAX_DELAY);
        ESP_LOGI(pcTaskGetTaskName(NULL), "recive bytes %d, str : %s", reciveBytes, pvRxData);
    }
    vTaskDelete(NULL);
}

// 发送数据
void send_data(void *pvParam)
{
    // 1条消息大概30长度
    char pvTxData[30];
    int pvTxDataLen = 0; // 字符串长度
    int txNum = 1;       // 发送次数
    while (1)
    {
        pvTxDataLen = sprintf(pvTxData, "hello world jun! %d", txNum);
        size_t sendBytes = xStreamBufferSend(streamBufferHandle,
                                             (void *)pvTxData,
                                             pvTxDataLen,
                                             0);
        if (sendBytes != pvTxDataLen)
        {
            ESP_LOGE(pcTaskGetTaskName(NULL), "The string could not be added to the message buffer because there was not enough free space in the buffer");
        }
        else
        {
            ESP_LOGI(pcTaskGetTaskName(NULL), "send bytes %d, str: %s", sendBytes, pvTxData);
        }
        txNum++;
        // 每秒发1条
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    // 大概收5条
    streamBufferHandle = xStreamBufferCreate(110, 10);
    vTaskSuspendAll();
    xTaskCreate(send_data, "send_data", 1024 * 5, NULL, 1, NULL);
    xTaskCreate(recive_data, "recive_data", 1024 * 5, NULL, 4, NULL);
    xTaskResumeAll();
}
