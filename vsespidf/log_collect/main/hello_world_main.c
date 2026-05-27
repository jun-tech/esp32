/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <time.h>
#include "esp_log.h"

// 当前日志个数
int logdata_size = 0;

typedef struct
{
    char message[256];
} log_entry_t;

typedef struct _log_data_t
{
    char log[256];
    struct _log_data_t *next_log_data;
    struct _log_data_t *prev_log_data;
} log_data_t;
// 日志列表头指针
log_data_t *logdatas_head;
// 日志列表尾指针
log_data_t *logdatas_last;

QueueHandle_t log_queue = NULL;
#define LOG_QUEUE_SIZE 20

static const char *TAG = "LOG";

int log_to_queue(const char *format, va_list args)
{
    struct tm timeinfo;
    time_t now = time(NULL);
    localtime_r(&now, &timeinfo);

    log_entry_t entry;
    int len = snprintf(entry.message, sizeof(entry.message), "[%04d-%02d-%02d %02d:%02d:%02d] ",
                       timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
                       timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    len += vsnprintf(entry.message + len, sizeof(entry.message) - len, format, args);

    if (xQueueSend(log_queue, &entry, 0) != pdTRUE)
    {
        // 这样会死循环
        // ESP_LOGE("LOG", "日志队列已满");
        printf("%s", "日志队列已满\r\n");
    }
    // 休闲10毫秒，防止多核竞争写日志
    vTaskDelay(pdMS_TO_TICKS(10));
    return len;
}

void log_dashboard_data(void *pvParameters)
{
    while (1)
    {
        log_entry_t entry;
        if (xQueueReceive(log_queue, &entry, portMAX_DELAY))
        {
            // 串口打印下写入日志
            printf("%s", entry.message);
            // 记录到看板
            log_data_t *p = (log_data_t *)malloc(sizeof(log_data_t));
            sprintf(p->log, "%s", entry.message);
            if (logdatas_head == NULL)
            {
                logdatas_head = p;
                logdatas_last = p;
            }
            else
            {
                // 已经有一个头指针
                // 当前头指针前一个为新对象
                logdatas_head->prev_log_data = p;
                p->next_log_data = logdatas_head;
                logdatas_head = p;
            }
            logdata_size++;
            // 只存n个
            if (logdata_size > 5)
            {
                log_data_t *free_log_data = logdatas_last;
                logdatas_last = logdatas_last->prev_log_data;
                logdatas_last->next_log_data = NULL;
                // 释放最后一个
                free(free_log_data);
                free_log_data = NULL;
                logdata_size--;
                // printf("log %d %s  1111111 \r\n", logdata_size, logdatas_last->log);
            }
        }
    }
}

void log_esp_task_collect()
{
    log_queue = xQueueCreate(LOG_QUEUE_SIZE, sizeof(log_entry_t));
    // xTaskCreatePinnedToCore(log_writer_task, "log_writer", 1024 * 4, NULL, 2, NULL, 1);
    esp_log_set_vprintf(log_to_queue);

    // 写到sdcard中，这里有bug，找不到原因，改为使用看板
    // log_writer_task(NULL);
    // 日志看板
    log_dashboard_data(NULL);
}

void log_esp_task_produce1()
{
    while (1)
    {
        ESP_LOGI("produce1", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void log_esp_task_produce2()
{
    while (1)
    {
        ESP_LOGI("produce2", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void log_esp_task_produce3()
{
    while (1)
    {
        ESP_LOGI("produce3", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void log_esp_task_produce4()
{
    while (1)
    {
        ESP_LOGI("produce4", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void log_esp_task_produce5()
{
    while (1)
    {
        ESP_LOGI("produce5", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void log_esp_task_produce6()
{
    while (1)
    {
        ESP_LOGI("produce6", "Free heap: %d bytes", esp_get_free_heap_size());
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    // 生产日志
    xTaskCreatePinnedToCore(log_esp_task_produce1, "log_esp_task_produce1", 1024 * 4, NULL, 0, NULL, 0);
    xTaskCreatePinnedToCore(log_esp_task_produce2, "log_esp_task_produce2", 1024 * 4, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(log_esp_task_produce3, "log_esp_task_produce3", 1024 * 4, NULL, 2, NULL, 0);
    xTaskCreatePinnedToCore(log_esp_task_produce4, "log_esp_task_produce4", 1024 * 4, NULL, 0, NULL, 1);
    xTaskCreatePinnedToCore(log_esp_task_produce5, "log_esp_task_produce5", 1024 * 4, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(log_esp_task_produce6, "log_esp_task_produce6", 1024 * 4, NULL, 2, NULL, 1);
    // 收录日志
    xTaskCreatePinnedToCore(log_esp_task_collect, "log_esp_task_collect", 1024 * 4, NULL, 2, NULL, 0);
}
