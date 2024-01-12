#ifndef SPI_MGR_H
#define SPI_MGR_H
#include "driver/spi_master.h"

/**
 * spi总线管理
 */
typedef struct
{
    // spi总线
    spi_host_device_t spi_host;
    spi_device_handle_t dev_handle;

    // 管脚
    int16_t pin_dc;
    int16_t pin_mosi;
    int16_t pin_miso;
    int16_t pin_sclk;
    int16_t pin_cs;
} DevSPI_t;

/**
 * 初始化总线，若miso不需要接线可以配置为-1
 */
void spi_mgr_bus_init(DevSPI_t *devspi);

/**
 * 往总线添加设备
 */
bool spi_mgr_bus_add_device(DevSPI_t *devspi, int clock_speed_hz, int16_t cs);

/**
 * 发送数据
 * @param data 数据
 * @param data_length 数据个数
 */
bool spi_write_byte(DevSPI_t *devspi, const uint8_t *data, size_t data_length);

/**
 * 发送指令,字节形式发送8bit
 */
bool spi_write_cmd(DevSPI_t *devspi, const uint8_t cmd);

/**
 * 发送指令,2字节形式发送16bit
 */
bool spi_write_cmd_word(DevSPI_t *devspi, const uint16_t cmd);

/**
 * 发送数据,字节形式发送8bit
 */
bool spi_write_data(DevSPI_t *devspi, const uint8_t data);
bool spi_write_datas(DevSPI_t *devspi, const uint8_t *datas, int len);

/**
 * 发送数据,字节形式发送16bit
 */
bool spi_write_data_word(DevSPI_t *devspi, const uint16_t data, int len);
bool spi_write_data_words(DevSPI_t *devspi, const uint16_t *datas, int len);
#endif