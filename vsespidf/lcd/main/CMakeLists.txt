set(srcs "main.c"
)

idf_component_register(SRCS ${srcs}
    INCLUDE_DIRS "."

    # REQUIRES spi_mgr lvgl lvgl_drivers
    REQUIRES spi_mgr tft_drivers
)
