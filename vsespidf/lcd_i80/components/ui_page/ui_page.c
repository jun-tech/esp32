#include <stdio.h>
#include "ui_page.h"
#include "lv_fs_if.h"
#include "esp_log.h"

static const char *TAG = "ui_page";
static uint8_t gindex = 0;

static void event_btn_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e); // 获取回调事件
    if (code == LV_EVENT_CLICKED)
    { // 点击事件
        ESP_LOGI(TAG, "Clicked");
        // e->target->user_data;
        create_page(gindex++);
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    { // 对象的值已经改变
        ESP_LOGI(TAG, "Toggled");
    }
}

lv_obj_t *create_page(uint8_t index)
{

    lv_obj_t *page = lv_obj_create(NULL);
    if (page != NULL && index % 2 == 0)
    {
        lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);

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
            lv_obj_t *btn1 = lv_btn_create(page);                             // 创建btn
            lv_obj_add_event_cb(btn1, event_btn_handler, LV_EVENT_ALL, NULL); // 创建按键回调函数
            lv_obj_align(btn1, LV_ALIGN_TOP_LEFT, 20, 20);                    // 居中对象
            lv_obj_t *label1 = lv_label_create(btn1);                         // 创建label
            lv_label_set_text(label1, "Button1");                             // 设置label字内容
            btn1->user_data = (void *)page;                                   // 跳转页

            lv_obj_t *labeltext = lv_label_create(page);
            lv_label_set_long_mode(labeltext, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
            lv_obj_set_width(labeltext, 120);
            lv_label_set_text(labeltext, buf);
            lv_obj_align(labeltext, LV_ALIGN_CENTER, 0, 40);
        }
    }
    else if (page != NULL && index % 2 == 1)
    {
        lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);

        // 添加按钮
        lv_obj_t *btn2 = lv_btn_create(page);                             // 创建btn
        lv_obj_add_event_cb(btn2, event_btn_handler, LV_EVENT_ALL, NULL); // 创建按键回调函数
        lv_obj_align(btn2, LV_ALIGN_TOP_LEFT, 20, 20);                    // 居中对象
        lv_obj_t *label2 = lv_label_create(btn2);                         // 创建label
        lv_label_set_text(label2, "Button2");                             // 设置label字内容
        btn2->user_data = (void *)page;                                   // 跳转页

        // 图片
        // lv_obj_t *image_bin = lv_img_create(lv_scr_act());
        lv_obj_t *image_bin = lv_img_create(page);
        lv_obj_set_width(image_bin, 200);
        lv_obj_set_height(image_bin, 200);
        lv_img_set_src(image_bin, "S:happy.bin");
        lv_obj_align(image_bin, LV_ALIGN_CENTER, 0, 40);
    }
    // lv_scr_load(page);
    lv_scr_load_anim(page, LV_SCR_LOAD_ANIM_NONE, 0, 0, true);
    return page;
}
