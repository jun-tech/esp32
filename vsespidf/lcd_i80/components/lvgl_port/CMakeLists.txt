idf_component_register(SRCS "lv_port_touch.c" "lv_port_disp.c" "lv_port_tick.c"
                       INCLUDE_DIRS "."
                       REQUIRES lvgl bsp esp_timer)
