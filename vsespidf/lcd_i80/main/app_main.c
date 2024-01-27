#include <esp_err.h>
#include <esp_log.h>
#include <esp_system.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_freertos_hooks.h"
#include "bsp_spi.h"

#include "lv_port_disp.h"
#include "lv_port_tick.h"
#include "lv_port_touch.h"
#include "lv_fs_if.h"

#include "lv_demos.h"

/*-----------------变量声明-----------------------------------*/
static lv_obj_t *page1 = NULL;
static lv_obj_t *page2 = NULL;
static int page_index = 1;
/*-----------------------------------------------------------*/

void lvgl_read_sdcard_test(void)
{
    // 创建屏幕1
    page1 = lv_obj_create(NULL);
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
            // lv_obj_t *label2 = lv_label_create(lv_scr_act());
            lv_obj_t *label2 = lv_label_create(page1);
            lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
            lv_obj_set_width(label2, 120);
            lv_label_set_text(label2, buf);
            lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
        }
    }

    // 创建屏幕2
    page2 = lv_obj_create(NULL);
    if (page2 != NULL)
    {
        lv_obj_set_size(page2, LV_HOR_RES, LV_VER_RES);
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
    // bsp_spi_bus_init(HSPI_HOST, 12 /* miso */, 13 /* mosi */, 14 /*sck*/);
    // lvgl 初始化
    lv_init();
    lv_port_disp_init();
    vTaskDelay(pdMS_TO_TICKS(200));
    // lv_fs_if_init(); // spi 总线在此初始化，sdcard 初始化
    // lv_port_touch_init(HSPI_HOST);
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
