#ifndef __BSP_LCD_H
#define __BSP_LCD_H

#include <stdint.h>

#include <esp_lcd_panel_io.h>

#include "bsp_lcd_panels.h"

#define LCD_X_PIXELS 320
#define LCD_Y_PIXELS 480

#define BSP_LCD_BL_PIN CONFIG_TFT_PIN_BL
#define BSP_LCD_CS_PIN CONFIG_TFT_PIN_CS
#define BSP_LCD_DC_PIN CONFIG_TFT_PIN_RS
#define BSP_LCD_WR_PIN CONFIG_TFT_PIN_WR
#define BSP_LCD_RST_PIN CONFIG_TFT_PIN_RST
#define BSP_LCD_DATA_PINS                                                                                                                                              \
    {                                                                                                                                                                  \
        CONFIG_TFT_PIN_DB0, CONFIG_TFT_PIN_DB1, CONFIG_TFT_PIN_DB2, CONFIG_TFT_PIN_DB3, CONFIG_TFT_PIN_DB4, CONFIG_TFT_PIN_DB5, CONFIG_TFT_PIN_DB6, CONFIG_TFT_PIN_DB7 \
    }
// 16位
//  13, 12, 14, 27, 26, 25, 33, 32

esp_lcd_panel_io_handle_t
lcd_i80_bus_io_init(uint16_t pclk_mhz, size_t transfer_size, esp_lcd_panel_io_color_trans_done_cb_t trans_done_cb, void *user_data);
void lcd_init_reg(const esp_lcd_panel_io_handle_t io, const lcd_panel_reg_t reg_table[]);
void lcd_draw_rect(const esp_lcd_panel_io_handle_t io, uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, const void *color_data);
void lcd_disp_switch(const esp_lcd_panel_io_handle_t io, bool sw);
esp_err_t lcd_bl_set(uint8_t brightness);

#endif
