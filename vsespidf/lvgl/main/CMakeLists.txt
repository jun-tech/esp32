idf_component_register(SRCS "sd_card_example_main.c" "lvgl_main.c"
    INCLUDE_DIRS ""
    REQUIRES lvgl_esp32_drivers lvgl fatfs
)
