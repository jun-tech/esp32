/* SD card and FAT filesystem example.
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

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

static const char *TAG = "example";

#define MOUNT_POINT "/sdcard"

// This example can use SDMMC and SPI peripherals to communicate with SD card.
// By default, SDMMC peripheral is used.
// To enable SPI mode, uncomment the following line:

// DMA channel to be used by the SPI peripheral
#define SPI_DMA_CHAN 1

// When testing SD and SPI modes, keep in mind that once the card has been
// initialized in SPI mode, it can not be reinitialized in SD mode without
// toggling power to the card.

// Pin mapping when using SPI mode.
// With this mapping, SD card can be used both in SPI and 1-line SD mode.
// Note that a pull-up on CS line is required in SD mode.
#define PIN_NUM_MISO 19
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK 18
#define PIN_NUM_CS 5

void app_main(void)
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
    host.max_freq_khz = 5000;

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
        return;
    }

    // 这将初始化没有卡检测（CD）和写保护（WP）信号的插槽。
    // 如果您的主板有这些信号，请修改slot_config.gpio_cd和slot_config.gpio_wp。
    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = PIN_NUM_CS;
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
        return;
    }

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);

    // 使用POSIX和C标准库函数来处理文件
    // First create a file.
    ESP_LOGI(TAG, "Opening file");
    FILE *f = fopen(MOUNT_POINT "/hello.txt", "w");
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open file for writing");
        return;
    }
    fprintf(f, "Hello %s!\n", card->cid.name);
    fclose(f);
    ESP_LOGI(TAG, "File written");

    // 重命名前检查目标文件是否存在
    struct stat st;
    if (stat(MOUNT_POINT "/foo.txt", &st) == 0)
    {
        // 删除（如果存在）
        unlink(MOUNT_POINT "/foo.txt");
    }

    // 重命名文件
    ESP_LOGI(TAG, "Renaming file");
    if (rename(MOUNT_POINT "/hello.txt", MOUNT_POINT "/foo.txt") != 0)
    {
        ESP_LOGE(TAG, "Rename failed");
        return;
    }

    // 读取文件
    ESP_LOGI(TAG, "Reading file");
    f = fopen(MOUNT_POINT "/foo.txt", "r"); // 读取方式打开文件
    if (f == NULL)
    {
        ESP_LOGE(TAG, "Failed to open file for reading");
        return;
    }
    char line[64];
    fgets(line, sizeof(line), f); // 读取一行数据
    fclose(f);                    // 关闭文件
    // 在字符串中查找换行
    char *pos = strchr(line, '\n');
    if (pos)
    {
        *pos = '\0'; // 替换为结束符
    }
    ESP_LOGI(TAG, "Read from file: '%s'", line);

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

    // 卸载分区并禁用SDMMC或SPI外设
    esp_vfs_fat_sdcard_unmount(mount_point, card);
    ESP_LOGI(TAG, "Card unmounted");

    // 卸载总线
    spi_bus_free(host.slot);
}

// 参考
// https://blog.csdn.net/qq_36347513/article/details/119680510