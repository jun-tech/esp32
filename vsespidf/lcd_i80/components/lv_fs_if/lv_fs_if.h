/**
 * @file lv_fs_if.h
 *
 */

/*File system interface*/
#define LV_USE_FS_IF 1
#if LV_USE_FS_IF
#define LV_FS_IF_FATFS 'S'
#define LV_FS_IF_PC '\0'
#define LV_FS_IF_POSIX '\0'
#endif /*LV_USE_FS_IF*/

#ifndef LV_FS_IF_H
#define LV_FS_IF_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************
 *      INCLUDES
 *********************/
#include <lvgl.h>

#if LV_USE_FS_IF

    /*********************
     *      DEFINES
     *********************/

    /**********************
     *      TYPEDEFS
     **********************/

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    /**
     * Register driver(s) for the File system interface
     */
    void lv_fs_if_init(void);

    /**********************
     *      MACROS
     **********************/

#endif /*LV_USE_FS_IF*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_FS_IF_H*/
