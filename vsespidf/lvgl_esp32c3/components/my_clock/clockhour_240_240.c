#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_CLOCKHOUR_240_240
#define LV_ATTRIBUTE_IMG_CLOCKHOUR_240_240
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_CLOCKHOUR_240_240 uint8_t clockhour_240_240_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0xe9, 0x05, 0xe4, 0x88, 0xe4, 0xed, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xee, 0xe4, 0x8a, 0xe9, 0x05, 
  0xe4, 0x7d, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0x80, 
  0xe4, 0xe5, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xe9, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xeb, 0xe4, 0x9a, 0xe4, 0x9a, 0xe4, 0xeb, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xec, 0xe4, 0x39, 0x00, 0x00, 0x00, 0x00, 0xe5, 0x38, 0xe4, 0xea, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xa6, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9a, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9b, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x9a, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xbf, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xfd, 0xe4, 0x89, 0xe4, 0x21, 0xe4, 0x21, 0xe4, 0x88, 0xe4, 0xfc, 0xe4, 0xff, 
  0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xed, 0xe4, 0xed, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 
  0xe4, 0xf1, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xf4, 
  0xe4, 0x9b, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0x9f, 
  0xe4, 0x15, 0xe4, 0xb3, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xff, 0xe4, 0xb7, 0xe4, 0x15, 
  0x00, 0x00, 0xe5, 0x18, 0xe4, 0x7f, 0xe4, 0xc2, 0xe4, 0xc4, 0xe4, 0x82, 0xe4, 0x19, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0xa6, 0xf9, 0x05, 0x04, 0xf1, 0x88, 0x04, 0xf1, 0xed, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xee, 0x04, 0xf1, 0x8a, 0xa6, 0xf9, 0x05, 
  0x04, 0xf1, 0x7d, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0x80, 
  0x04, 0xf1, 0xe5, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xe9, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xeb, 0x04, 0xf1, 0x9a, 0x04, 0xf1, 0x9a, 0x04, 0xf1, 0xeb, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xec, 0x04, 0xf1, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x38, 0x04, 0xf1, 0xea, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0xa6, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9a, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xf1, 0x9a, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0xf0, 0xbf, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xfd, 0x04, 0xf1, 0x89, 0x04, 0xf1, 0x21, 0x04, 0xf1, 0x21, 0x04, 0xf1, 0x88, 0x04, 0xf1, 0xfc, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xed, 0x04, 0xf1, 0xed, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 
  0x04, 0xf1, 0xf1, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xf4, 
  0x04, 0xf1, 0x9b, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0x9f, 
  0xc3, 0xf0, 0x15, 0x04, 0xf1, 0xb3, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xff, 0x04, 0xf1, 0xb7, 0xc3, 0xf0, 0x15, 
  0x00, 0x00, 0x00, 0x04, 0xe9, 0x18, 0x04, 0xf1, 0x7f, 0x04, 0xf1, 0xc2, 0x04, 0xf1, 0xc4, 0xe4, 0xf0, 0x82, 0x04, 0xe9, 0x19, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0xf9, 0xa6, 0x05, 0xf1, 0x04, 0x88, 0xf1, 0x04, 0xed, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xee, 0xf1, 0x04, 0x8a, 0xf9, 0xa6, 0x05, 
  0xf1, 0x04, 0x7d, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0x80, 
  0xf1, 0x04, 0xe5, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xe9, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xeb, 0xf1, 0x04, 0x9a, 0xf1, 0x04, 0x9a, 0xf1, 0x04, 0xeb, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xec, 0xf1, 0x04, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x38, 0xf1, 0x04, 0xea, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0xa6, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9a, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0x04, 0x9a, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xe4, 0xbf, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xfd, 0xf1, 0x04, 0x89, 0xf1, 0x04, 0x21, 0xf1, 0x04, 0x21, 0xf1, 0x04, 0x88, 0xf1, 0x04, 0xfc, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xed, 0xf1, 0x04, 0xed, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 
  0xf1, 0x04, 0xf1, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xf4, 
  0xf1, 0x04, 0x9b, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0x9f, 
  0xf0, 0xc3, 0x15, 0xf1, 0x04, 0xb3, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xff, 0xf1, 0x04, 0xb7, 0xf0, 0xc3, 0x15, 
  0x00, 0x00, 0x00, 0xe9, 0x04, 0x18, 0xf1, 0x04, 0x7f, 0xf1, 0x04, 0xc2, 0xf1, 0x04, 0xc4, 0xf0, 0xe4, 0x82, 0xe9, 0x04, 0x19, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x33, 0x33, 0xff, 0x05, 0x1e, 0x1e, 0xee, 0x88, 0x1e, 0x1e, 0xef, 0xed, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xee, 0x1e, 0x1e, 0xee, 0x8a, 0x33, 0x33, 0xff, 0x05, 
  0x1f, 0x1f, 0xef, 0x7d, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x80, 
  0x1e, 0x1e, 0xef, 0xe5, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xe9, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xeb, 0x1e, 0x1e, 0xee, 0x9a, 0x1e, 0x1e, 0xee, 0x9a, 0x1e, 0x1e, 0xef, 0xeb, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xec, 0x1f, 0x1f, 0xed, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xed, 0x38, 0x1f, 0x1f, 0xef, 0xea, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1f, 0x1f, 0xf0, 0xa7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0xf0, 0xa6, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xee, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xee, 0x9a, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0xee, 0x9a, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x1d, 0xef, 0xbf, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xfd, 0x1e, 0x1e, 0xee, 0x89, 0x1f, 0x1f, 0xf0, 0x21, 0x1f, 0x1f, 0xf0, 0x21, 0x1e, 0x1e, 0xee, 0x88, 0x1e, 0x1e, 0xef, 0xfc, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xed, 0x1e, 0x1e, 0xef, 0xed, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 
  0x1e, 0x1e, 0xef, 0xf1, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xf4, 
  0x1e, 0x1e, 0xef, 0x9b, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0x9f, 
  0x18, 0x18, 0xf3, 0x15, 0x1e, 0x1e, 0xef, 0xb3, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1e, 0x1e, 0xef, 0xff, 0x1f, 0x1f, 0xf0, 0xb7, 0x18, 0x18, 0xf3, 0x15, 
  0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xea, 0x18, 0x1e, 0x1e, 0xef, 0x7f, 0x1e, 0x1e, 0xef, 0xc2, 0x1e, 0x1e, 0xef, 0xc4, 0x1d, 0x1d, 0xef, 0x82, 0x1f, 0x1f, 0xeb, 0x19, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t clockhour_240_240 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 8,
  .header.h = 45,
  .data_size = 360 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .data = clockhour_240_240_map,
};