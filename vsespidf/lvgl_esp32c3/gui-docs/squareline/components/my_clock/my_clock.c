#include <stdio.h>
#include <time.h>
#include "my_clock.h"
#include "lvgl.h"
#include "esp_log.h"

static time_t timep;        // 时间戳
static struct tm time_temp; // 具体时间，小时为24小时制

lv_obj_t *img1;

static void time_refresh(lv_event_t *event)
{
    // 获取当前时间
    time(&timep);
    memcpy(&time_temp, localtime(&timep), sizeof(struct tm));

    lv_img_set_angle(img1, time_temp.tm_sec * 60);
    // lv_img_set_angle(lvMinute, time_temp.tm_min * 60);
    // lv_img_set_angle(lvHour, time_temp.tm_hour * 300);
}

static void send_event(void)
{
    lv_event_send(img1, LV_EVENT_REFRESH, NULL);
}

void my_clock_init(void)
{

    static lv_style_t style; // 创建样式
    lv_style_init(&style);   // 初始化样式

    // lv_style_set_radius(&style, 5); // 设置样式的圆角
    // lv_style_set_bg_opa(&style, LV_OPA_COVER);                             // 设置样式背景透明度
    // lv_style_set_bg_color(&style, lv_palette_lighten(LV_PALETTE_GREY, 3)); // 设置样式的背景颜色

    // lv_style_set_border_width(&style, 2);                                // 设置样式边框宽度
    // lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_BLUE)); // 设置样式边框颜色

    lv_style_set_img_recolor(&style, lv_palette_main(LV_PALETTE_BLUE)); // 设置图片样式重新着着
    lv_style_set_img_recolor_opa(&style, LV_OPA_50);                    // 设置图片样式透明度
    lv_style_set_transform_angle(&style, 300);                          // 设置图片样式角度

    // 1、绘制背景
    LV_IMG_DECLARE(bg);
    lv_obj_t *screen = lv_scr_act();
    lv_obj_t *bg_img = lv_img_create(screen);
    lv_img_set_src(bg_img, &bg);
    lv_obj_align(bg_img, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(bg_img, 240, 240);

    // 2、esplogo
    LV_IMG_DECLARE(esp_logo);

    img1 = lv_img_create(bg_img);
    lv_obj_add_style(img1, &style, 0); // 将样式添加到图片对象中
    lv_img_set_src(img1, &esp_logo);
    lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_size(img1, 96, 96);
    lv_img_set_angle(img1, 0); // 0度角

    lv_obj_t *img2 = lv_img_create(lv_scr_act());
    lv_img_set_src(img2, LV_SYMBOL_OK "Accept");
    lv_obj_align_to(img2, img1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    /* 刷新时间回调 */
    lv_obj_add_event_cb(img1, time_refresh, LV_EVENT_REFRESH, NULL);
    /* 发送刷新事件 */
    lv_timer_create((void *)send_event, 1000, NULL);
}
