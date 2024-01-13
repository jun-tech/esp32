set(srcs "main.c" "lv_port_disp.c"
)

idf_component_register(SRCS ${srcs}
    INCLUDE_DIRS "."

    REQUIRES spi_mgr tft_drivers lvgl
)
