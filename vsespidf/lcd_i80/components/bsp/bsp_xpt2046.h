#ifndef BSP_XPT_2046_H
#define BSP_XPT_2046_H

/*********************
 *      INCLUDES
 *********************/

#include <stdint.h>
#include <stdbool.h>
#include "driver/spi_master.h"
#include "lvgl.h"

/*********************
 *      DEFINES
 *********************/
#define XPT2046_IRQ 26

#define XPT2046_AVG 4
#define XPT2046_X_MIN 200
#define XPT2046_Y_MIN 120
#define XPT2046_X_MAX 1900
#define XPT2046_Y_MAX 1900
#define XPT2046_X_INV 1
#define XPT2046_Y_INV 1
#define XPT2046_XY_SWAP 1
#define XPT2046_TOUCH_THRESHOLD 400 // Threshold for touch detection
#define XPT2046_TOUCH_IRQ 1

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void xpt2046_init(spi_host_device_t host, uint16_t cs, uint16_t pen_irq);
bool xpt2046_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

#endif