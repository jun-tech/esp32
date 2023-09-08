/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

#define BLINK_GPIO 2

static uint8_t s_led_state = 0;

void led_init()
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void led_task(void *pvParameters)
{

    while (1)
    {
        // 翻转状态
        s_led_state = !s_led_state;
        // 开关灯
        gpio_set_level(BLINK_GPIO, s_led_state);
        // 1秒闪一次
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    // 执行完毕需要删除任务，不然freertos会认为假死而重启，一般上面的循环不会到这里
    vTaskDelete(NULL);
}

void app_main(void)
{

    // 外设要在main处初始化
    led_init();

    // freertos task start
    xTaskCreate(led_task, "ledTask", 1024, NULL, 1, NULL);
}