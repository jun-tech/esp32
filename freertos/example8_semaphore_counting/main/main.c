#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 计算信号量跟二值信号量区别在于，计算信号量可记录信号量释放的次数，可监视同一资源上的多个实例
 * 下面模拟餐店，食客进出餐店时，餐位余数场景
 */
SemaphoreHandle_t semaphoreLock;

// 进店，信号量减操作
void personEatIn(void *pvParam)
{
    while (1)
    {
        // 取位
        UBaseType_t seatCount = uxSemaphoreGetCount(semaphoreLock);
        ESP_LOGI("personEat", "Now left seat %d, ", seatCount);
        UBaseType_t takeSeatFlag = xSemaphoreTake(semaphoreLock, 0);
        if (takeSeatFlag == pdPASS)
        {
            ESP_LOGI("personEatIn", "Take the seat! eating... ");
        }
        else
        {
            ESP_LOGW("personEatIn", "Take the seat fail! awaiting...");
        }
        // delay下，让其他task调度
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

// 离店，信号量加操作
void personEatOut(void *pvParam)
{
    while (1)
    {
        // 食客用餐完毕后离开，这里模拟3秒用餐时间
        vTaskDelay(pdMS_TO_TICKS(3000));
        // 释放信号量
        xSemaphoreGive(semaphoreLock);
        // 离店
        ESP_LOGI("personEatOut", "I'm full! Step out of the restaurant. ");
    }
}

void app_main(void)
{
    // 信号量10，假设餐店里有10个座位
    semaphoreLock = xSemaphoreCreateCounting(10, 10);
    if (semaphoreLock != NULL)
    {
        xSemaphoreGive(semaphoreLock);
        // 下面模拟外面有n个食客进餐店吃饭，餐店满人，剩下的食客只能等待场景
        xTaskCreatePinnedToCore(personEatIn, "personEatIn", 1024 * 5, NULL, 1, NULL, 0);
        xTaskCreatePinnedToCore(personEatOut, "personEatOut", 1024 * 5, NULL, 1, NULL, 1);
    }
}
