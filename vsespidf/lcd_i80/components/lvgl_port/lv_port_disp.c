#include "lv_port_disp.h"

#include <esp_log.h>
#include <esp_heap_caps.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "freertos/semphr.h"

#include "lvgl.h"

#include "bsp_lcd.h"

#include "sdkconfig.h"

static const char *TAG = "lv_port_disp";

/**
 * @brief 总线传输完成后，回调此函数
 *
 * @param panel_io
 * @param edata
 * @param user_ctx
 * @return true
 * @return false
 */
static bool notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    // 感觉总线传输完调刷新，不是很平滑
    /* 通知lvgl传输已完成 */
    // lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    // lv_disp_flush_ready(disp_driver);
    // return false;
    return true;
}

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    /* 启动新的传输 */
    lcd_draw_rect(disp_drv->user_data, area->x1, area->y1, area->x2, area->y2, color_p);
    lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init()
{
    /* 创建并初始化用于在lvgl中注册显示设备的结构 */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv); // 使用默认值初始化该结构

    /* 初始化LCD总线 */
    static esp_lcd_panel_io_handle_t panel_io;                                                                                                  // 需要全程生命周期，设置为静态变量
    panel_io = lcd_i80_bus_io_init(CONFIG_LVGL_LCD_PCLK_FREQ, LVGL_BUFF_SIZE * sizeof(lv_color_t), notify_lvgl_flush_ready, (void *)&disp_drv); // 初始化8080并行总线

/* 初始化寄存器 */
#if defined(CONFIG_LVGL_LCD_PANEL_W350CE024A_40Z)
    lcd_init_reg(panel_io, panel_st7796s_w350ce024a_40z_reg_table);
#elif defined(CONFIG_LVGL_LCD_PANEL_CL35BC1017_40A)
    lcd_init_reg(panel_io, panel_st7796s_cl35bc1017_40a_reg_table);
#elif defined(CONFIG_LVGL_LCD_PANEL_CL35BC106_40A)
    lcd_init_reg(panel_io, panel_ili9488_cl35bc106_40a_reg_table);
#endif

    ESP_LOGI(TAG, "lcd clock: %dMHz, mininal fps: %d", CONFIG_LVGL_LCD_PCLK_FREQ,
             CONFIG_LVGL_LCD_PCLK_FREQ * 1000000 / (LCD_X_PIXELS * LCD_Y_PIXELS));

    /* 申请lvgl渲染缓冲区 */
    lv_color_t *lvgl_draw_buff1 = heap_caps_malloc(LVGL_BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    lv_color_t *lvgl_draw_buff2 = heap_caps_malloc(LVGL_BUFF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    /* 向lvgl注册缓冲区 */
    static lv_disp_draw_buf_t draw_buf_dsc; // 需要全程生命周期，设置为静态变量
    lv_disp_draw_buf_init(&draw_buf_dsc, lvgl_draw_buff1, lvgl_draw_buff2, LVGL_BUFF_SIZE);

    /* 设置屏幕分辨率 */
    disp_drv.hor_res = LCD_X_PIXELS;
    disp_drv.ver_res = LCD_Y_PIXELS;
    /* 将总线句柄放入lv_disp_drv_t中用户自定义段 */
    disp_drv.user_data = panel_io;
    /* 设置显示矩形函数，用于将矩形缓冲区刷新到屏幕上 */
    disp_drv.flush_cb = disp_flush;
    /* 设置缓冲区 */
    disp_drv.draw_buf = &draw_buf_dsc;
    /* 注册显示设备 */
    lv_disp_drv_register(&disp_drv);

    /* 开启显示 */
    lcd_disp_switch(panel_io, true);
}
