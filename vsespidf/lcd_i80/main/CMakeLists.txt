set(srcs "app_main.c"
)

idf_component_register( SRCS ${srcs}
                        INCLUDE_DIRS "" 
                        REQUIRES driver lv_fs_if bsp lvgl_port ui_page ws2812b_led_strip ui)

