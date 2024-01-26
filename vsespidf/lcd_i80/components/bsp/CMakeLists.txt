idf_component_register(SRCS "bsp_spi.c" "bsp_xpt2046.c" "bsp_lcd.c" "bsp_lcd_panels.c"
                       INCLUDE_DIRS "."
                       REQUIRES esp_lcd driver lvgl)
