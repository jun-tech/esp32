#include "app_sdcard.h"
#include "esp_log.h"
#include "esp_camera.h"
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "driver/sdmmc_host.h"
#include "dirent.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Jpeg2AVI.h"
// 组件放到idf
#include "avi_recorder.h"
#include "file_sort.h"

#define MOUNT_POINT "/sdcard"

static const char *TAG = "app_sdcard";

sdmmc_card_t *card;

void show_sdcard_files_info(sdmmc_card_t *card)
{
    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);

    // 查看当前磁盘一级目录文件
    int i = 0;
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    if ((dir = opendir(MOUNT_POINT)) == NULL)
    {
        ESP_LOGE(TAG, "opendir failed!");
        return;
    }
    else
    {
        while ((entry = readdir(dir)) != NULL)
        {
            i++;
            /*
            esp32 FAT 编码
            为了更好支持中文文件名，建议在menuconfig里面更改文件编码设置：(Top) →Component config →FAT Filesystem support
            * OEM Code Page (simplified Chinese (DBCS) (CP936))
            * Long filename support (Long filename buffer in heap )
            * (255) Max long filename length
            * API character encoding (API uses UTF-8 encoding )
            * (0) Number of simultaneously open files protected by lock function
            * (10000) Timeout for acquiring a file lock, ms
            * Use separate cache for each file
            * Perfer external RAM when allocating FATFS buffers
            */
            ESP_LOGI(TAG, "filename%d = %s, filetype = %d", i, entry->d_name, entry->d_type); // 输出文件或者目录的名称,输出文件类型
        }

        closedir(dir);
    }
}

// sdcard 已用
void sdcard_usage(size_t *usage)
{
    // 查看当前磁盘一级目录文件
    int i = 0;
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    // 信息
    char entrypath[1024];
    struct stat entry_stat;
    const char *entrytype;

    if ((dir = opendir(MOUNT_POINT)) == NULL)
    {
        ESP_LOGE(TAG, "opendir failed!");
        return;
    }
    else
    {
        while ((entry = readdir(dir)) != NULL)
        {
            // 如果是文件
            if (entry->d_type != DT_DIR)
            {
                entrytype = (entry->d_type == DT_DIR ? "directory" : "file");
                // 路径
                sprintf(entrypath, "%s/%s", MOUNT_POINT, entry->d_name);
                // 查看文件信息
                if (stat(entrypath, &entry_stat) == -1)
                {
                    ESP_LOGE(TAG, "Failed to stat %s : %s", entrytype, entry->d_name);
                    continue;
                }
                *usage = *usage + entry_stat.st_size;
            }

            i++;
            // ESP_LOGI(TAG, "filename%d = %s, filetype = %d", i, entry->d_name, entry->d_type); // 输出文件或者目录的名称,输出文件类型
        }

        closedir(dir);
    }
}

void sdcard_remove(int num)
{

    // 处理路径
    char dest[200] = {0};
    strncpy(dest, MOUNT_POINT, strlen(MOUNT_POINT) + 1);
    // 排序处理
    file_info_t *file_info_list = NULL;
    file_list_sort(dest, &file_info_list);

    // 删除计算
    int i = 0;
    char filepath[200];
    file_info_t *current_file = file_info_list;
    // 释放
    file_info_t *free_file = NULL;
    while (current_file != NULL)
    {
        // 删除
        if (current_file->file_type != DT_DIR && i < num)
        {
            sprintf(filepath, "%s/%s", MOUNT_POINT, current_file->file_name);
            unlink(filepath);
            i++;
            ESP_LOGI(TAG, "file%d = %s, remove success", i, filepath);
        }

        // 释放
        free_file = current_file;
        current_file = current_file->next_file;
        free(free_file);
        free_file = NULL;
    }

    // char filepath[500];
    // DIR *dir = NULL;
    // struct dirent *entry = NULL;
    // if ((dir = opendir(MOUNT_POINT)) == NULL)
    // {
    //     ESP_LOGE(TAG, "opendir failed!");
    //     return;
    // }
    // else
    // {
    //     while ((entry = readdir(dir)) != NULL && i < num)
    //     {
    //         // 如果是文件
    //         if (entry->d_type != DT_DIR)
    //         {
    //             sprintf(filepath, "%s/%s", MOUNT_POINT, entry->d_name);
    //             unlink(filepath);
    //             i++;
    //             ESP_LOGI(TAG, "file%d = %s, remove success", i, filepath);
    //         }
    //     }
    // }
    // closedir(dir);
}

static int _get_frame(void **buf, size_t *len)
{
    camera_fb_t *image_fb = esp_camera_fb_get();
    if (!image_fb)
    {
        ESP_LOGE(TAG, "Camera capture failed");
        return -1;
    }
    else
    {
        // ESP_LOGI(TAG, "len=%d, w=%d, h=%d", image_fb->len, image_fb->width, image_fb->height);
        *buf = &image_fb->buf;
        *len = image_fb->len;
    }
    return 0;
}

static int _return_frame(void *inbuf)
{
    camera_fb_t *image_fb = __containerof(inbuf, camera_fb_t, buf);
    esp_camera_fb_return(image_fb);
    image_fb = NULL;
    return 0;
}

esp_err_t get_video_size(int *w, int *h)
{
    camera_fb_t *image_fb = esp_camera_fb_get();
    if (!image_fb)
    {
        ESP_LOGE(TAG, "Camera capture failed");
        *w = resolution[FRAMESIZE_QSXGA].width;
        *h = resolution[FRAMESIZE_QSXGA].height;
        return ESP_FAIL;
    }
    else
    {
        *w = image_fb->width;
        *h = image_fb->height;
        esp_camera_fb_return(image_fb);
        image_fb = NULL;
        return ESP_OK;
    }
}

void save_video(void *vparams)
{
    int video_w = 0;
    int video_h = 0;
    // 时间戳
    time_t now;
    char fname[64];
    struct tm *timeinfo;

    while (1)
    {
        time(&now);
        timeinfo = localtime(&now);
        strftime(fname, 80, MOUNT_POINT "/record_%Y%m%d_%H%M.avi", timeinfo);
        // 保存视频
        esp_err_t flag = get_video_size(&video_w, &video_h);
        if (flag == ESP_OK)
        {
            ESP_LOGI(TAG, "record video w=%d, h=%d", video_w, video_h);
        }
        else
        {
            // 报错
            continue;
        }
        // 统计下已用
        size_t total = 1024 * 1024 * 1024 * 1; // 1G
        size_t usage = 0;
        sdcard_usage(&usage);
        ESP_LOGI(TAG, "usage %d(Bytes), total %d(Bytes)", usage, total);
        if (usage > 0)
        {
            // 超过70%, 删除20个
            float precent = ((float)usage * 100) / (float)total;
            ESP_LOGI(TAG, "usage %.2f(Precent)", precent);
            if (precent > 70)
            {
                sdcard_remove(20);
            }
        }
        // 记录视频
        avi_recorder_start(fname, _get_frame, _return_frame, video_w, video_h, 60, 1);
        avi_recorder_stop();
        // 歇1分钟，不然发烫容易烧sdcard
        vTaskDelay(pdMS_TO_TICKS(60 * 1000));
    }

    vTaskDelete(NULL);
}

void app_sdcard_main()
{
    ESP_LOGI(TAG, "%s", "sdcard main");

    esp_err_t ret;

    // Options for mounting the filesystem.
    // If format_if_mount_failed is set to true, SD card will be partitioned and
    // formatted in case when mounting fails.
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        // #ifdef CONFIG_EXAMPLE_FORMAT_IF_MOUNT_FAILED
        .format_if_mount_failed = true,
        // #else
        // .format_if_mount_failed = false,
        // #endif // EXAMPLE_FORMAT_IF_MOUNT_FAILED
        .max_files = 5,
        .allocation_unit_size = 16 * 1024};
    const char mount_point[] = MOUNT_POINT;
    ESP_LOGI(TAG, "Initializing SD card");

    // Use settings defined above to initialize SD card and mount FAT filesystem.
    // Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
    // Please check its source code and implement error recovery when developing
    // production applications.

    ESP_LOGI(TAG, "Using SDMMC peripheral");
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
    host.max_freq_khz = SDMMC_FREQ_HIGHSPEED;

    // This initializes the slot without card detect (CD) and write protect (WP) signals.
    // Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

    // Set bus width to use:
#ifdef CONFIG_EXAMPLE_SDMMC_BUS_WIDTH_4
    slot_config.width = 4;
    ESP_LOGI(TAG, "Using 4 wire mode");
#else
    slot_config.width = 1;
    ESP_LOGI(TAG, "Using 1 wire mode");
#endif

    // Enable internal pullups on enabled pins. The internal pullups
    // are insufficient however, please make sure 10k external pullups are
    // connected on the bus. This is for debug / example purpose only.
    slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

    ESP_LOGI(TAG, "Mounting filesystem");
    ret = esp_vfs_fat_sdmmc_mount(mount_point, &host, &slot_config, &mount_config, &card);

    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
        {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                          "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        }
        else
        {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                          "Make sure SD card lines have pull-up resistors in place.",
                     esp_err_to_name(ret));
        }
        return;
    }
    ESP_LOGI(TAG, "Filesystem mounted");

    // 查看sdcard文件
    // show_sdcard_files_info(card);
    // 保存视频
    xTaskCreate(save_video, "saveVideo", 1024 * 5, (void *)card, 1, NULL);

    // All done, unmount partition and disable SDMMC peripheral
    // esp_vfs_fat_sdcard_unmount(mount_point, card);
    // ESP_LOGI(TAG, "Card unmounted");
}