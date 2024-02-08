
SET(SOURCES  my_clock.c
             esp_logo.c
             bg.c)

idf_component_register(SRCS  ${SOURCES}
    INCLUDE_DIRS "include"
    REQUIRES lvgl)