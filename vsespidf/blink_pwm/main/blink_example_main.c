/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "driver/ledc.h"

static const char *TAG = "example";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/

// 硬件配置
#define LEDC_GPIO_PIN 2             // PWM输出引脚
#define LEDC_CHANNEL LEDC_CHANNEL_0 // 使用通道0
#define LEDC_TIMER LEDC_TIMER_0     // 使用定时器0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_DUTY_RESOLUTION LEDC_TIMER_13_BIT // 13位分辨率（8192级亮度）
#define LEDC_FREQUENCY 5000                    // PWM频率5kHz

// 呼吸灯参数
#define BREATH_CYCLE_MS 3000 // 完整呼吸周期3秒
#define BREATH_STEP_MS 20    // 亮度变化步长20ms

// 全局变量
static ledc_channel_config_t ledc_channel = {0};
static ledc_timer_config_t ledc_timer = {0};

void app_main(void)
{
    // 1. 配置定时器
    ledc_timer.speed_mode = LEDC_MODE;
    ledc_timer.timer_num = LEDC_TIMER;
    ledc_timer.duty_resolution = LEDC_DUTY_RESOLUTION;
    ledc_timer.freq_hz = LEDC_FREQUENCY;
    ledc_timer.clk_cfg = LEDC_AUTO_CLK;
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // 2. 配置通道
    ledc_channel.speed_mode = LEDC_MODE;
    ledc_channel.channel = LEDC_CHANNEL;
    ledc_channel.timer_sel = LEDC_TIMER;
    ledc_channel.intr_type = LEDC_INTR_DISABLE;
    ledc_channel.gpio_num = LEDC_GPIO_PIN;
    ledc_channel.duty = 0; // 初始占空比为0
    ledc_channel.hpoint = 0;
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));

    // 3. 呼吸灯逻辑
    const int max_duty = (1 << LEDC_DUTY_RESOLUTION) - 1; // 最大占空比（8191）
    int direction = 1;                                    // 1=渐亮，-1=渐暗
    int current_duty = 0;

    while (1)
    {
        // 更新占空比
        current_duty += direction * (max_duty * BREATH_STEP_MS) / BREATH_CYCLE_MS;

        // 边界检测
        if (current_duty >= max_duty)
        {
            current_duty = max_duty;
            direction = -1;
        }
        else if (current_duty <= 0)
        {
            current_duty = 0;
            direction = 1;
        }

        // 设置占空比
        ESP_ERROR_CHECK(ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, current_duty));
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);

        // 延时
        vTaskDelay(pdMS_TO_TICKS(BREATH_STEP_MS));
    }
}