# set(COMPONENT_SRCS "opencv_process.cpp" "app_main.c" "app_sdcard.c" "app_wifi.c" "app_camera.c" "app_httpd.c" "app_mdns.c" "app_sdcard.c" "Jpeg2AVI.c" "list.c")
# set(COMPONENT_ADD_INCLUDEDIRS "include")

# set(COMPONENT_REQUIRES
# esp32-camera
# esp-face
# nvs_flash
# esp_http_server
# fb_gfx
# mdns
# fatfs
# )

# set(COMPONENT_EMBED_FILES
# "www/index_ov2640.html.gz"
# "www/index_ov3660.html.gz"
# "www/index_ov5640.html.gz"
# "www/monitor.html.gz")

# register_component()
# 上面的cmake是原有写法，下面整合opencv的写法

idf_component_register(
    SRCS
    Jpeg2AVI.c
    list.c
    app_sdcard.c
    app_main.c
    app_wifi.c
    app_camera.c
    app_httpd.c
    app_mdns.c
    app_sdcard.c

    # opencv_process.cpp
    INCLUDE_DIRS
    .
    include

    # opencv/
    EMBED_FILES
    "www/index_ov2640.html.gz"

    # "www/index_ov3660.html.gz"
    # "www/index_ov5640.html.gz"
    "www/monitor.html.gz"
)

# Be aware that the order of the librairies is important
# add_prebuilt_library(opencv_imgcodecs "opencv/libopencv_imgcodecs.a")
# add_prebuilt_library(libpng "opencv/3rdparty/liblibpng.a")
# add_prebuilt_library(libzlib "opencv/3rdparty/libzlib.a")
# add_prebuilt_library(opencv_imgproc "opencv/libopencv_imgproc.a")
# add_prebuilt_library(opencv_core "opencv/libopencv_core.a")
# add_prebuilt_library(ade "opencv/libade.a")

# set(IMGCODEC_DEP libpng libzlib)
# target_link_libraries(opencv_imgcodecs INTERFACE ${IMGCODEC_DEP})

# set(CORE_DEP libzlib)
# target_link_libraries(opencv_core INTERFACE ${CORE_DEP})

# set(OPENCV_DEP opencv_imgcodecs opencv_imgproc opencv_core)
# target_link_libraries(${COMPONENT_LIB} ${OPENCV_DEP})
