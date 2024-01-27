#include <stdio.h>
#include "lvgl_sdcard.h"
#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdspi_host.h"
#include "driver/spi_common.h"
#include "driver/sdmmc_types.h"
#include "sdmmc_cmd.h"
#include "sdkconfig.h"
#include "dirent.h"

static const char *TAG = "sdcard";

#define MOUNT_POINT "/sdcard"

// DMA 1被 lvgl 使用，改用2
#define SPI_DMA_CHAN CONFIG_SDCARD_SPI_DMA_CHAN
// SPI2 已经被lvgl占用换3
#if SOC_SPI_PERIPH_NUM == 0
#define SD_SPI_HOST SPI1_HOST
#elif SOC_SPI_PERIPH_NUM == 1
#define SD_SPI_HOST SPI2_HOST
#elif SOC_SPI_PERIPH_NUM > 2
#define SD_SPI_HOST SPI3_HOST
#else
#define SD_SPI_HOST SPI2_HOST
#endif

// 管脚定义
// #define PIN_NUM_MISO 19
// #define PIN_NUM_MOSI 23
// #define PIN_NUM_CLK 18
// #define PIN_NUM_CS 5

#define PIN_NUM_MISO CONFIG_SDCARD_PIN_MISO
#define PIN_NUM_MOSI CONFIG_SDCARD_PIN_MOSI
#define PIN_NUM_CLK CONFIG_SDCARD_PIN_CLK
#define PIN_NUM_CS CONFIG_SDCARD_PIN_CS

esp_err_t sdcard_init(void)
{
    esp_err_t ret;
    // Options for mounting the filesystem.
    // If format_if_mount_failed is set to true, SD card will be partitioned and
    // formatted in case when mounting fails.
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {                                 // 文件系统挂载配置
                                                     .format_if_mount_failed = false, // 如果挂载失败：true会重新分区和格式化/false不会重新分区和格式化
                                                     .max_files = 5,                  // 打开文件最大数量
                                                     .allocation_unit_size = 16 * 1024};
    sdmmc_card_t *card;                     // SD / MMC卡信息结构
    const char mount_point[] = MOUNT_POINT; // 根目录
    ESP_LOGI(TAG, "Initializing SD card");

    // Use settings defined above to initialize SD card and mount FAT filesystem.
    // Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
    // Please check its source code and implement error recovery when developing
    // production applications.
    ESP_LOGI(TAG, "Using SPI peripheral");

    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    // 此处更改成5000，否则报ESP_ERR_INVALID_CRC错误
    // host.max_freq_khz = 5000;
    host.max_freq_khz = 20000; // 20MHz
    // SPI2 已经被lvgl占用换3
    host.slot = SD_SPI_HOST;

    // 外部已经初始化，所以注释掉，共用HSPI
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = PIN_NUM_MOSI,
        .miso_io_num = PIN_NUM_MISO,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 4000,
    };
    // SPI总线初始化
    ret = spi_bus_initialize(host.slot, &bus_cfg, SPI_DMA_CHAN);
    if (ret != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to initialize bus.");
        return ret;
    }

    // 这将初始化没有卡检测（CD）和写保护（WP）信号的插槽。
    // 如果您的主板有这些信号，请修改slot_config.gpio_cd和slot_config.gpio_wp。
    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = 27;
    slot_config.host_id = host.slot;

    // 挂载文件系统
    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);

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
        return ret;
    }

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);
    return ret;
}
