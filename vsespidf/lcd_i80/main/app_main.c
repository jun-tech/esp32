#include <esp_err.h>
#include <esp_log.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/semphr.h"

#include "esp_freertos_hooks.h"
#include "driver/gpio.h"
#include "bsp_spi.h"
#include "esp_log.h"

#include "lv_port_disp.h"
#include "lv_port_tick.h"
#include "lv_port_touch.h"
#include "lv_fs_if.h"

#include "lv_demos.h"
#include "ui_page.h"
#include "ws2812b_led_strip.h"
#include "ui.h"

/*-----------------变量声明-----------------------------------*/
#if CONFIG_HOST_SPI
#define BUS_SPI_HOST SPI1_HOST
#elif CONFIG_HOST_HSPI
#define BUS_SPI_HOST SPI2_HOST
#elif CONFIG_HOST_VSPI
#define BUS_SPI_HOST SPI3_HOST
#else
#define BUS_SPI_HOST SPI2_HOST
#endif

static const char *TAG = "main";
static size_t i = 0;
lv_timer_t *lv_tm;
/*-----------------------------------------------------------*/

/*-----------------LVGL变量声明-----------------------------------*/
static SemaphoreHandle_t xGuiSemaphore;
TaskHandle_t xTask;
/*-----------------变量声明-----------------------------------*/

static void lv_tm_cb(lv_timer_t *tmr);

void lvgl_read_sdcard_test(void)
{
    lv_tm = lv_timer_create(lv_tm_cb, 600, 0);
    create_page(i++);
}

// 定时器，界面不断
static void lv_tm_cb(lv_timer_t *tmr)
{
    ESP_LOGI(TAG, "page %d", i);
    create_page(i++);
    // 测试翻页100次
    if (i > 1000)
    {
        lv_timer_del(lv_tm);
    }
}

/* LVGL 移植部分 */
// static void lv_tick_task(void *arg)
// {
//     (void)arg;
//     lv_tick_inc(portTICK_PERIOD_MS);
// }

static void gui_demo()
{
    // 开启sdcard
    // lvgl_read_sdcard_dir_test();
    // lvgl_read_sdcard_test();
    // lvgl_bg_color_test();
    // lvgl_test();
    // lv_demo_widgets();
    // lv_demo_keypad_encoder();
    // lv_demo_music();
    // lv_demo_printer();
    // 以下2案例性能测试
    // lv_demo_benchmark();
    // lv_demo_stress();
    //
    ui_init();
}

/* UI 任务 */
static void gui_task(void *arg)
{
    while (1)
    {

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            lv_timer_handler();
            xSemaphoreGive(xGuiSemaphore);
        }

        // 算出需要多少空间
        // UBaseType_t stackLeft = uxTaskGetStackHighWaterMark(xTask);
        // ESP_LOGI("task1", "stackLeft : %d", stackLeft);
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        // 这里让下idle task
        vTaskDelay(pdMS_TO_TICKS(20));
    }

    vTaskDelete(NULL);
}

// ws2812b
void led_task()
{
    // led_strip_rainbrow();
    led_strip_breathing();
    vTaskDelete(NULL);
}

// 主函数
void app_main(void)
{
    xGuiSemaphore = xSemaphoreCreateMutex();

    // 初始化========================================================
    // spi总线
    bsp_spi_bus_init(BUS_SPI_HOST, CONFIG_SPI_PIN_MISO /* miso */, CONFIG_SPI_PIN_MOSI /* mosi */, CONFIG_SPI_PIN_CLK /*sck*/);

    // 先把电阻触摸、sdcard片选引脚拉高
    // 拉高
    gpio_pad_select_gpio(CONFIG_XPT_PIN_CS);
    gpio_set_direction(CONFIG_XPT_PIN_CS, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_XPT_PIN_CS, 1);
    // 拉高
    gpio_pad_select_gpio(CONFIG_SDCARD_PIN_CS);
    gpio_set_direction(CONFIG_SDCARD_PIN_CS, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_SDCARD_PIN_CS, 1);
    // 电阻笔
    gpio_pad_select_gpio(CONFIG_XPT_PIN_IRQ);
    gpio_set_direction(CONFIG_XPT_PIN_IRQ, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_XPT_PIN_IRQ, 1);
    // 彩灯
    gpio_pad_select_gpio(1);
    gpio_set_direction(1, GPIO_MODE_OUTPUT);
    gpio_set_level(1, 0);

    // lvgl 初始化
    lv_init();
    lv_port_disp_init();
    lv_fs_if_init(); // sdcard 初始化
    lv_port_touch_init(BUS_SPI_HOST);
    lv_create_tick();
    // esp_register_freertos_tick_hook((void *)lv_tick_task);
    gui_demo();

    xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 4, NULL, 1, &xTask, 0);
    xTaskCreatePinnedToCore(led_task, "led task", 1024 * 4, NULL, 1, &xTask, 0);
    // xTaskCreate(gui_task, "gui task", 1024 * 4, NULL, 1, NULL);
}