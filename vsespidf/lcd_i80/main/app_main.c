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
/*-----------------------------------------------------------*/

/*-----------------变量声明-----------------------------------*/
static const char *TAG = "main";
static lv_obj_t *page1 = NULL;
static lv_obj_t *page2 = NULL;
/*-----------------------------------------------------------*/

static void event_btn_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e); // 获取回调事件
    if (code == LV_EVENT_CLICKED)
    { // 点击事件
        ESP_LOGI(TAG, "Clicked");
        lv_obj_t *page = (lv_obj_t *)e->target->user_data;
        if (page != NULL)
        {
            lv_scr_load(page);

            // 模拟读一次
            lv_fs_file_t f;
            lv_fs_res_t res;
            // res = lv_fs_open(&f, "S:folder/foo.txt", LV_FS_MODE_RD); // 这里的S:folder文件夹下的foo.txt
            res = lv_fs_open(&f, "S:foo.txt", LV_FS_MODE_RD); // 读取根目录foo.txt
            if (res != LV_FS_RES_OK)
            {
                ESP_LOGE("sdcard_file", "open fail");
            }
            else
            {
                ESP_LOGI("sdcard_file", "open ok");
                uint32_t read_num;
                char buf[20];
                res = lv_fs_read(&f, buf, sizeof(buf), &read_num);
                ESP_LOGI("main", "read:%s", buf);
                lv_fs_close(&f);
            }
        }
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    { // 对象的值已经改变
        ESP_LOGI(TAG, "Toggled");
    }
}

void lvgl_read_sdcard_test(void)
{
    // 创建屏幕1
    page1 = lv_obj_create(NULL);
    page2 = lv_obj_create(NULL);
    if (page1 != NULL)
    {
        lv_obj_set_size(page1, LV_HOR_RES, LV_VER_RES);

        lv_fs_file_t f;
        lv_fs_res_t res;
        // res = lv_fs_open(&f, "S:folder/foo.txt", LV_FS_MODE_RD); // 这里的S:folder文件夹下的foo.txt
        res = lv_fs_open(&f, "S:foo.txt", LV_FS_MODE_RD); // 读取根目录foo.txt
        if (res != LV_FS_RES_OK)
        {
            ESP_LOGE("sdcard_file", "open fail");
        }
        else
        {
            ESP_LOGI("sdcard_file", "open ok");
            uint32_t read_num;
            char buf[20];
            res = lv_fs_read(&f, buf, sizeof(buf), &read_num);
            ESP_LOGI("main", "read:%s", buf);
            lv_fs_close(&f);

            // 屏幕显示
            // 添加按钮
            lv_obj_t *btn1 = lv_btn_create(page1);                            // 创建btn
            lv_obj_add_event_cb(btn1, event_btn_handler, LV_EVENT_ALL, NULL); // 创建按键回调函数
            lv_obj_align(btn1, LV_ALIGN_TOP_LEFT, 20, 20);                    // 居中对象
            lv_obj_t *label1 = lv_label_create(btn1);                         // 创建label
            lv_label_set_text(label1, "Button1");                             // 设置label字内容
            btn1->user_data = (void *)page2;                                  // 跳转页

            lv_obj_t *labeltext = lv_label_create(page1);
            lv_label_set_long_mode(labeltext, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
            lv_obj_set_width(labeltext, 120);
            lv_label_set_text(labeltext, buf);
            lv_obj_align(labeltext, LV_ALIGN_CENTER, 0, 40);
        }
    }

    // 创建屏幕2
    if (page2 != NULL)
    {
        lv_obj_set_size(page2, LV_HOR_RES, LV_VER_RES);

        // 添加按钮
        lv_obj_t *btn2 = lv_btn_create(page2);                            // 创建btn
        lv_obj_add_event_cb(btn2, event_btn_handler, LV_EVENT_ALL, NULL); // 创建按键回调函数
        lv_obj_align(btn2, LV_ALIGN_TOP_LEFT, 20, 20);                    // 居中对象
        lv_obj_t *label2 = lv_label_create(btn2);                         // 创建label
        lv_label_set_text(label2, "Button2");                             // 设置label字内容
        btn2->user_data = (void *)page1;                                  // 跳转页

        // 图片
        // lv_obj_t *image_bin = lv_img_create(lv_scr_act());
        lv_obj_t *image_bin = lv_img_create(page2);
        lv_obj_set_width(image_bin, 200);
        lv_obj_set_height(image_bin, 200);
        lv_img_set_src(image_bin, "S:happy.bin");
        lv_obj_align(image_bin, LV_ALIGN_CENTER, 0, 40);
    }

    lv_scr_load(page2);
}

void app_main(void)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(10);

    // spi总线
    bsp_spi_bus_init(BUS_SPI_HOST, CONFIG_SPI_PIN_MISO /* miso */, CONFIG_SPI_PIN_MOSI /* mosi */, CONFIG_SPI_PIN_CLK /*sck*/);

    // 先把电阻触摸、sdcard片选引脚拉高
    // 拉高
    gpio_reset_pin(CONFIG_XPT_PIN_CS);
    gpio_set_direction(CONFIG_XPT_PIN_CS, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_XPT_PIN_CS, 1);
    // 拉高
    gpio_reset_pin(CONFIG_SDCARD_PIN_CS);
    gpio_set_direction(CONFIG_SDCARD_PIN_CS, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_SDCARD_PIN_CS, 1);
    // 电阻笔
    gpio_reset_pin(CONFIG_XPT_PIN_IRQ);
    gpio_set_direction(CONFIG_XPT_PIN_IRQ, GPIO_MODE_OUTPUT);
    gpio_set_level(CONFIG_XPT_PIN_IRQ, 1);

    // lvgl 初始化
    lv_init();
    lv_port_disp_init();
    lv_fs_if_init(); // sdcard 初始化
    lv_port_touch_init(BUS_SPI_HOST);
    lv_create_tick();

    // 演示
    // lv_demo_widgets();
    lv_demo_music();
    // lv_demo_benchmark();
    // lv_demo_stress();
    // lvgl_read_sdcard_test();

    while (1)
    {
        lv_timer_handler();
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}
