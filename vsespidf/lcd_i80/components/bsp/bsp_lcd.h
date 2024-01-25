#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include <stdint.h>

#include <esp_lcd_panel_io.h>

#include "bsp_lcd_panels.h"

#define LCD_X_PIXELS 320
#define LCD_Y_PIXELS 480

#define BSP_LCD_BL_PIN -1
#define BSP_LCD_CS_PIN 2
#define BSP_LCD_DC_PIN 15
#define BSP_LCD_WR_PIN 16
#define BSP_LCD_RST_PIN 17
#define BSP_LCD_DATA_PINS           \
    {                               \
        5, 18, 19, 21, 3, 1, 22, 23 \
    }
// 16位
//  13, 12, 14, 27, 26, 25, 33, 32

esp_lcd_panel_io_handle_t
lcd_i80_bus_io_init(uint16_t pclk_mhz, size_t transfer_size);
void lcd_init_reg(const esp_lcd_panel_io_handle_t io, const lcd_panel_reg_t reg_table[]);
void lcd_draw_rect(const esp_lcd_panel_io_handle_t io, uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, const void *color_data);
void lcd_disp_switch(const esp_lcd_panel_io_handle_t io, bool sw);
esp_err_t lcd_bl_set(uint8_t brightness);

#endif
