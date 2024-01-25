cmake_minimum_required(VERSION 3.5)

add_compile_options(-fdiagnostics-color=always)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp32s3-8080lcd-demo)
