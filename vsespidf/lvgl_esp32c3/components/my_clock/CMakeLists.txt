
SET(SOURCES  my_clock.c
             esp_logo.c
             bg.c
             bg_240_240.c
             bg2_240_240.c
             clockhour_240_240.c
             clockmin_240_240.c
             clocksec_240_240.c
             )

idf_component_register(SRCS  ${SOURCES}
    INCLUDE_DIRS "include"
    REQUIRES lvgl)