#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"

/**
 * 简单任务
 */
void task1(void *pvParam)
{
    int i = 0;
    while (1)
    {
        ESP_LOGI("task1", "Call method : %d", i);
        i++;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

/**
 * 任务参数--------------------------------------------------------------------------------
 */
int i = 1;
char str[] = "hello";
typedef struct my_struct
{
    int i;
    char *str;
} MyStruct;
MyStruct mystruct = {0, "hello struct"};

void task2(void *pvParam)
{
    int *pInt;
    pInt = (int *)pvParam;
    ESP_LOGI("task2", "value : %d", *pInt);
    vTaskDelete(NULL);
}

void task3(void *pvParam)
{
    char *pStr;
    pStr = (char *)pvParam;
    ESP_LOGI("task3", "value : %s", pStr);
    vTaskDelete(NULL);
}

void task4(void *pvParam)
{
    MyStruct *pStruct;
    pStruct = (MyStruct *)pvParam;
    ESP_LOGI("task4", "value : %d,str : %s", pStruct->i, pStruct->str);
    vTaskDelete(NULL);
}

void app_main(void)
{
    TaskHandle_t xTask;
    // 简单任务，优先级设置为1（数值越大优先级越高），最优化栈配置可以查看下面的任务信息
    xTaskCreate(task1, "task1", 1024 * 5, NULL, 1, &xTask);
    xTaskCreate(task2, "task2", 3460, (void *)&i, 2, NULL);
    xTaskCreate(task3, "task3", 3460, (void *)str, 3, NULL);
    xTaskCreate(task4, "task4", 1024 * 5, (void *)&mystruct, 3, NULL);
    // 双核写法
    xTaskCreatePinnedToCore(task4, "task5", 1024 * 5, (void *)&mystruct, 3, NULL, 1);
    // vTaskList 需要打开配置menuconfig - freertos 打勾
    // Enable FreeRTOS trace facility
    // Enable FreeRTOS stats formatting functions
    // Enable display of xCoreID in vTaskList
    // 打印task信息，调优分配内存
    static char pcWriteBuffer[512] = {0};
    vTaskList(pcWriteBuffer);
    printf("Name    State   Priority    Stack   Num\n");
    printf("%s\n", pcWriteBuffer);
    // 查看task堆栈使用情况
    while (1)
    {
        UBaseType_t stackLeft = uxTaskGetStackHighWaterMark(xTask);
        ESP_LOGI("task1", "stackLeft : %d", stackLeft);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
