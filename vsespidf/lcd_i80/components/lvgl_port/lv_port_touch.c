#include "lv_port_touch.h"
#include "bsp_spi.h"
#include "bsp_xpt2046.h"
#include "esp_log.h"
#include "lvgl.h"

lv_indev_t *indev_touchpad;

static void touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
    bool res = false;
    res = xpt2046_read(indev_drv, data);
    data->continue_reading = res;
}

void lv_port_touch_init(spi_host_device_t host)
{
    // 触摸屏初始化
    xpt2046_init(host, CONFIG_XPT_PIN_CS, CONFIG_XPT_PIN_IRQ);
    // lvgl输入设备驱动
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv);
}