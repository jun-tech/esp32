#include <stdio.h>
#include <time.h>
#include "my_clock.h"
#include "lvgl.h"
#include "esp_log.h"

static time_t timep;        // 时间戳
static struct tm time_temp; // 具体时间，小时为24小时制

lv_obj_t *clocksec;
lv_obj_t *clockmin;
lv_obj_t *clockhour;

static void time_refresh(lv_event_t *event)
{
    // 获取当前时间
    time(&timep);
    memcpy(&time_temp, localtime(&timep), sizeof(struct tm));

    lv_img_set_angle(clocksec, time_temp.tm_sec * 60);
    lv_img_set_angle(clockmin, time_temp.tm_min * 60);
    lv_img_set_angle(clockhour, time_temp.tm_hour * 300);
}

static void send_event(void)
{
    lv_event_send(clocksec, LV_EVENT_REFRESH, NULL);
}

void my_clock_init(void)
{
    // 1、绘制背景
    LV_IMG_DECLARE(bg_240_240);
    lv_obj_t *screen = lv_scr_act();
    lv_obj_t *bg_img = lv_img_create(screen);
    lv_img_set_src(bg_img, &bg_240_240);
    lv_obj_align(bg_img, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(bg_img, 240, 240);

    // 2、clock 绘制

    // 时针
    LV_IMG_DECLARE(clockhour_240_240);
    clockhour = lv_img_create(bg_img);
    lv_img_set_src(clockhour, &clockhour_240_240);
    lv_obj_set_pos(clockhour, 120 - 8 / 2, 120 - 45 - 13); // 指针位置
    lv_obj_set_size(clockhour, 8, 45);
    lv_img_set_angle(clockhour, 0);              // 0度角
    lv_img_set_pivot(clockhour, 8 / 2, 45 + 13); // 围绕Image坐标旋转 ，-13是偏移量

    // 分针
    LV_IMG_DECLARE(clockmin_240_240);
    clockmin = lv_img_create(bg_img);
    lv_img_set_src(clockmin, &clockmin_240_240);
    lv_obj_set_pos(clockmin, 120 - 8 / 2, 120 - 80 - 13); // 指针位置
    lv_obj_set_size(clockmin, 8, 80);
    lv_img_set_angle(clockmin, 0);              // 0度角
    lv_img_set_pivot(clockmin, 8 / 2, 80 + 13); // 围绕Image坐标旋转

    // 秒针
    LV_IMG_DECLARE(clocksec_240_240);
    clocksec = lv_img_create(bg_img);
    lv_img_set_src(clocksec, &clocksec_240_240);
    lv_obj_set_pos(clocksec, 120 - 19 / 2, 120 - 107 + 13); // 指针位置
    lv_obj_set_size(clocksec, 19, 107);
    lv_img_set_angle(clocksec, 0);                // 0度角
    lv_img_set_pivot(clocksec, 19 / 2, 107 - 13); // 围绕Image坐标旋转

    /* 刷新时间回调 */
    lv_obj_add_event_cb(clocksec, time_refresh, LV_EVENT_REFRESH, NULL);
    /* 发送刷新事件 */
    lv_timer_create((void *)send_event, 1000, NULL);
}
