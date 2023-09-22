set(COMPONENT_SRCS "app_main.c" "app_sdcard.c" "app_wifi.c" "app_camera.c" "app_httpd.c" "app_sdcard.c" "app_sntp_main.c")
set(COMPONENT_ADD_INCLUDEDIRS "include")

set(COMPONENT_REQUIRES
    esp32-camera
    esp-face
    nvs_flash
    esp_http_server
    fb_gfx
    mdns
    fatfs
    avi_video_process
    jpeg2avi
)

set(COMPONENT_EMBED_FILES
    "www/index_ov2640.html.gz"
    "www/monitor.html.gz")

register_component()
