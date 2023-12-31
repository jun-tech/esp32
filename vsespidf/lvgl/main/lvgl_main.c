#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "esp_log.h"
#include "esp_system.h"
#include "esp_freertos_hooks.h"

#include "lvgl.h"
#include "lvgl_helpers.h"
#include "lv_fs_if.h"

#include "lv_demos.h"

/*-----------------函数声明-----------------------------------*/
void lvgl_test(void);
void lvgl_bg_color_test(void);
void lvgl_read_sdcard_dir_test(void);
void lvgl_read_sdcard_test(void);
static void lv_tm_cb(lv_timer_t *tmr);
/*-----------------------------------------------------------*/

/*-----------------变量声明-----------------------------------*/
static lv_obj_t *page1 = NULL;
static lv_obj_t *page2 = NULL;
static lv_timer_t *lv_tm;
static int page_index = 0;
/*-----------------------------------------------------------*/

/* LVGL 移植部分 */
static void lv_tick_task(void *arg)
{
    (void)arg;
    lv_tick_inc(portTICK_PERIOD_MS);
}
SemaphoreHandle_t xGuiSemaphore;

static void gui_demo()
{
    // 开启sdcard
    // lvgl_read_sdcard_dir_test();
    lvgl_read_sdcard_test();
    // lvgl_bg_color_test();
    // lvgl_test();
    // lv_demo_widgets();
    // lv_demo_keypad_encoder();
    // lv_demo_music();
    // lv_demo_printer();
    // 以下2案例性能测试
    // lv_demo_benchmark();
    // lv_demo_stress();
}

// 定时器
static void lv_tm_cb(lv_timer_t *tmr)
{
    // ESP_LOGI("lv_tm_cb", "page %d", page_index);
    // 过渡画面
    if (page_index == 0)
    {
        lv_scr_load(page1);
    }
    else
    {
        // lv_scr_load_anim(page2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 300, 0, false);
        // lv_scr_load_anim(page2, LV_SCR_LOAD_ANIM_OVER_LEFT, 1000, 0, false);
        lv_scr_load_anim(page2, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, false);
        // lv_scr_load(page2);
    }
    page_index++;

    // 超过屏幕数，切换回第一屏幕
    if (page_index > 1)
    {
        page_index = 0;
    }
}

/* UI 任务 */
static void gui_task(void *arg)
{
    xGuiSemaphore = xSemaphoreCreateMutex();
    lv_init();          // lvgl内核初始化
    lv_fs_if_init();    // sdcard 初始化
    lvgl_driver_init(); // lvgl显示接口初始化

    static lv_disp_draw_buf_t draw_buf;
    lv_color_t *buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_color_t *buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, DISP_BUF_SIZE); /*Initialize the display buffer*/

    static lv_disp_drv_t disp_drv;         /*A variable to hold the drivers. Must be static or global.*/
    lv_disp_drv_init(&disp_drv);           /*Basic initialization*/
    disp_drv.draw_buf = &draw_buf;         /*Set an initialized buffer*/
    disp_drv.flush_cb = disp_driver_flush; /*Set a flush callback to draw to the display*/
    disp_drv.hor_res = LV_HOR_RES_MAX;     /*Set the horizontal resolution in pixels*/
    disp_drv.ver_res = LV_VER_RES_MAX;     /*Set the vertical resolution in pixels*/

    /* When using a monochrome display we need to register the callbacks:
     * - rounder_cb
     * - set_px_cb */
#ifdef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    disp_drv.rounder_cb = disp_driver_rounder;
    disp_drv.set_px_cb = disp_driver_set_px;
#endif
    lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    esp_register_freertos_tick_hook((void *)lv_tick_task);

    gui_demo();
    ESP_LOGI("main", "begin timer");
    lv_tm = lv_timer_create(lv_tm_cb, 5000, 0);

    while (1)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY))
        {
            lv_timer_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

void lvgl_bg_color_test(void)
{
    // base bg color
    static lv_style_t style;
    lv_style_init(&style);
    // lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_RED, 1));// 颜色纯度
    lv_style_set_bg_color(&style, lv_palette_main(LV_PALETTE_RED)); // 单色

    lv_obj_t *obj = lv_obj_create(lv_scr_act()); // 创建对象
    lv_obj_add_style(obj, &style, 0);            // 设置对象的样式
    lv_obj_set_size(obj, LV_HOR_RES_MAX / 3, LV_VER_RES_MAX);
    lv_obj_set_pos(obj, 0, 0);

    lv_obj_t *obj1 = lv_obj_create(lv_scr_act());                          // 创建对象
    lv_obj_add_style(obj1, &style, 0);                                     // 设置对象的样式
    lv_obj_set_style_bg_color(obj1, lv_palette_main(LV_PALETTE_GREEN), 0); // 单色
    lv_obj_set_size(obj1, LV_HOR_RES_MAX / 3, LV_VER_RES_MAX);
    lv_obj_set_pos(obj1, LV_HOR_RES_MAX / 3, 0);

    lv_obj_t *obj2 = lv_obj_create(lv_scr_act());                         // 创建对象
    lv_obj_add_style(obj2, &style, 0);                                    // 设置对象的样式
    lv_obj_set_style_bg_color(obj2, lv_palette_main(LV_PALETTE_BLUE), 0); // 单色
    lv_obj_set_size(obj2, LV_HOR_RES_MAX / 3, LV_VER_RES_MAX);
    lv_obj_set_pos(obj2, (LV_HOR_RES_MAX / 3) * 2, 0);
}

// lvgl测试
void lvgl_test(void)
{
    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP); /*Break the long lines*/
    lv_label_set_recolor(label1, true);                 /*Enable re-coloring by commands in the text*/
    lv_label_set_text(label1, "#0000ff Re-color# #ff00ff words# #ff0000 of a# label, align the lines to the center"
                              "and  wrap long text automatically.");
    lv_obj_set_width(label1, 120); /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label1, LV_ALIGN_CENTER, 0, -40);

    lv_obj_t *label2 = lv_label_create(lv_scr_act());
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label2, 120);
    lv_label_set_text(label2, "It is a circularly scrolling text. ");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 40);
}

void lvgl_read_sdcard_dir_test(void)
{
    lv_fs_dir_t dir;
    lv_fs_res_t res;
    // res = lv_fs_dir_open(&dir, "S:folder"); // 遍历folder文件夹
    res = lv_fs_dir_open(&dir, "S:"); // 遍历sdcard一级目录
    if (res != LV_FS_RES_OK)
    {
        ESP_LOGE("sdcard_dir", "open fail");
        return;
    }

    char fn[256];
    while (1)
    {
        res = lv_fs_dir_read(&dir, fn);
        if (res != LV_FS_RES_OK)
        {
            ESP_LOGE("sdcard_dir", "open fail");
            break;
        }

        /*fn is empty, if not more files to read*/
        if (strlen(fn) == 0)
        {
            break;
        }

        printf("%s\n", fn);
    }

    lv_fs_dir_close(&dir);
}

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

    lv_scr_load(page1);
}

// 主函数
void app_main(void)
{
    xTaskCreatePinnedToCore(gui_task, "gui task", 1024 * 4, NULL, 1, NULL, 0);
}
