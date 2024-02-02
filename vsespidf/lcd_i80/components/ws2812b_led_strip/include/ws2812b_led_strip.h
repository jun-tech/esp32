#ifndef WS2812B_LED_STRIP_H
#define WS2812B_LED_STRIP_H

#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/rmt.h"
#include "led_strip.h"

#define RMT_TX_CHANNEL RMT_CHANNEL_0

#define EXAMPLE_CHASE_SPEED_MS (10)

#define CONFIG_EXAMPLE_RMT_TX_GPIO 1

#define CONFIG_EXAMPLE_STRIP_LED_NUMBER 3

void led_strip_hsv2rgb(uint32_t h, uint32_t s, uint32_t v, uint32_t *r, uint32_t *g, uint32_t *b);

void led_main();

#endif