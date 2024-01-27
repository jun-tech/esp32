#ifndef BSP_XPT_2046_H
#define BSP_XPT_2046_H

/*********************
 *      INCLUDES
 *********************/

#include <stdint.h>
#include <stdbool.h>
#include "driver/spi_master.h"

/*********************
 *      DEFINES
 *********************/
#define MAX_LEN 3
#define XPT_START 0x80
#define XPT_XPOS 0x50
#define XPT_YPOS 0x10
#define XPT_8BIT 0x80
#define XPT_SER 0x04
#define XPT_DEF 0x03

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void xpt2046_init(spi_host_device_t host, uint16_t pin_cs, uint16_t pen_irq);
bool xpt2046_read();

#endif