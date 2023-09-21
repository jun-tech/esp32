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

#define MOUNT_POINT "/sdcard"

static const char *TAG = "app_sdcard";

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

void sd_write_jpg(const char *_jpg_buf, int _jpg_buf_len)
{
    time_t now;
    char fname[64];
    struct tm timeinfo;

    time(&now);
    // Set timezone to China Standard Time
    setenv("TZ", "CST-8", 1);
    tzset();

    localtime_r(&now, &timeinfo);
    sprintf(fname, MOUNT_POINT "/%08x.jpg", (unsigned int)now);
    ESP_LOGI(TAG, "fname:%s", fname);
    // 上面先用系统时间生成文件名，然后开始写入流程
    FILE *f = fopen(fname, "w");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }
    // 进行写入数据
    fwrite(_jpg_buf, _jpg_buf_len, 1, f);
    fclose(f);
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
        // ESP_LOGI(TAG, "len=%d", image_fb->len);
        *buf = &image_fb->buf;
        *len = image_fb->len;
    }
    return 0;
}

static int _return_frame(void *inbuf)
{
    camera_fb_t *image_fb = __containerof(inbuf, camera_fb_t, buf);
    esp_camera_fb_return(image_fb);
    return 0;
}

void save_video(void *vparams)
{
    while (1)
    {
        // 时间戳
        time_t now;
        char fname[64];
        struct tm timeinfo;

        time(&now);
        // Set timezone to China Standard Time
        setenv("TZ", "CST-8", 1);
        tzset();

        localtime_r(&now, &timeinfo);
        // sprintf(fname, MOUNT_POINT "/recorde_%08x.avi", (unsigned int)now);
        sprintf(fname, MOUNT_POINT "/recorde_%02x%02x%02x%02x%02x.avi", timeinfo.tm_year, timeinfo.tm_mon, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min);

        // 保存视频
        avi_recorder_start(fname, _get_frame, _return_frame, resolution[FRAMESIZE_QSXGA].width, resolution[FRAMESIZE_QSXGA].height, 60, 1);
        avi_recorder_stop();
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
#ifdef CONFIG_EXAMPLE_FORMAT_IF_MOUNT_FAILED
        .format_if_mount_failed = true,
#else
        .format_if_mount_failed = false,
#endif // EXAMPLE_FORMAT_IF_MOUNT_FAILED
        .max_files = 5,
        .allocation_unit_size = 16 * 1024};
    sdmmc_card_t *card;
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
    xTaskCreate(save_video, "saveVideo", 1024 * 10, (void *)card, 1, NULL);

    // All done, unmount partition and disable SDMMC peripheral
    // esp_vfs_fat_sdcard_unmount(mount_point, card);
    // ESP_LOGI(TAG, "Card unmounted");
}