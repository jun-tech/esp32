#include <stdio.h>
#include "spi_mgr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define TAG "spi_mgr"

void spi_mgr_bus_init(DevSPI_t *devspi)
{
    esp_err_t ret;

    ESP_LOGI(TAG, "MISO=%d", devspi->pin_miso);
    ESP_LOGI(TAG, "MOSI=%d", devspi->pin_mosi);
    ESP_LOGI(TAG, "SCLK=%d", devspi->pin_sclk);

    spi_bus_config_t buscfg = {
        .miso_io_num = devspi->pin_miso,
        .mosi_io_num = devspi->pin_mosi,
        .sclk_io_num = devspi->pin_sclk,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 81920};
    ret = spi_bus_initialize(devspi->spi_host, &buscfg, SPI_DMA_CH_AUTO);
    ESP_LOGI(TAG, "spi_bus_initialize ret=%d SPI_HOST=%d", ret, devspi->spi_host);
    assert(ret == ESP_OK);
}

// spi传送前回调
static void IRAM_ATTR spi_pre_transfer_callback(spi_transaction_t *t)
{
    // int dc = (int)t->user;
    // ESP_LOGI(TAG, "dc: %d", dc);
}

static void IRAM_ATTR spi_post_transfer_callback(spi_transaction_t *t)
{
    // 发送完毕回调
}

// 往总线添加设备
bool spi_mgr_bus_add_device(DevSPI_t *devspi, int clock_speed_hz)
{
    esp_err_t ret;

    ESP_LOGI(TAG, "CS=%d", devspi->pin_cs);
    gpio_reset_pin(devspi->pin_cs);
    gpio_set_direction(devspi->pin_cs, GPIO_MODE_OUTPUT);
    gpio_set_level(devspi->pin_cs, 1);

    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = clock_speed_hz,
        .spics_io_num = devspi->pin_cs, // 中断发送，这里不用赋值，否则中断发送不出去
        .queue_size = 6,
        .pre_cb = spi_pre_transfer_callback,   // Specify pre-transfer callback to handle D/C line
        .post_cb = spi_post_transfer_callback, // 发送后回调
        .flags = SPI_DEVICE_NO_DUMMY | SPI_DEVICE_HALFDUPLEX,
    };

    ret = spi_bus_add_device(devspi->spi_host, &devcfg, &(devspi->dev_handle));
    ESP_LOGI(TAG, "spi_bus_add_device=%d", ret);
    assert(ret == ESP_OK);

    return true;
}

bool spi_write_byte(DevSPI_t *devspi, const uint8_t *data, size_t data_length)
{
    esp_err_t ret;
    static spi_transaction_t t;
    if (data_length > 0)
    {
        memset(&t, 0, sizeof(spi_transaction_t));
        t.length = data_length * 8; // 每个数据8位，乘以数据长度，得出数据总长度
        t.tx_buffer = data;
#if 0
        // 以中断方式发送，添加设备时不用配置cs
        gpio_set_level(devspi->pin_cs, 0); // 片选拉低
        ret = spi_device_transmit(devspi->dev_handle, &t);
#endif

#if 1
        // 以轮询方式发送
        ret = spi_device_polling_transmit(devspi->dev_handle, &t);
#endif

#if 0
        ret = spi_device_queue_trans(devspi->dev_handle, &t, portMAX_DELAY);
        assert(ret == ESP_OK);
        // 1个队列，马上发出
        spi_queue_trans_yield(devspi);
#endif

        assert(ret == ESP_OK);
    }

    return true;
}

bool spi_queue_trans_datas(DevSPI_t *devspi, const uint8_t *datas, int data_length)
{
    esp_err_t ret;
    static spi_transaction_t t;
    if (data_length > 0)
    {
        memset(&t, 0, sizeof(spi_transaction_t));
        t.length = data_length * 8; // 每个数据8位，乘以数据长度，得出数据总长度
        t.tx_buffer = datas;
        // 队列方式发送
        gpio_set_level(devspi->pin_dc, 1); // 发送数据，dc管脚设置1
        ret = spi_device_queue_trans(devspi->dev_handle, &t, portMAX_DELAY);
        assert(ret == ESP_OK);
    }
    return true;
}

bool spi_queue_trans_yield(DevSPI_t *devspi)
{
    esp_err_t ret;
    spi_transaction_t *r_trans;
    ret = spi_device_get_trans_result(devspi->dev_handle, &r_trans, portMAX_DELAY);
    assert(ret == ESP_OK);
    return true;
}

bool spi_write_cmd(DevSPI_t *devspi, const uint8_t cmd)
{
    gpio_set_level(devspi->pin_dc, 0); // 发送指令，dc管脚设置0
    bool flag = spi_write_byte(devspi, &cmd, 1);
    assert(flag == true);
    return true;
}

bool spi_write_cmd_word(DevSPI_t *devspi, const uint16_t cmd)
{
    return true;
}

bool spi_write_data(DevSPI_t *devspi, const uint8_t data)
{
    gpio_set_level(devspi->pin_dc, 1);
    bool flag = spi_write_byte(devspi, &data, 1);
    assert(flag == true);
    return flag;
}

bool spi_write_datas(DevSPI_t *devspi, const uint8_t *datas, int len)
{
    gpio_set_level(devspi->pin_dc, 1); // 发送数据，dc管脚设置1
    bool flag = spi_write_byte(devspi, datas, len);
    assert(flag == true);
    return true;
}

bool spi_write_data_word(DevSPI_t *devspi, const uint16_t data, int len)
{
    static uint8_t Byte[2];
    Byte[0] = (data >> 8) & 0xFF;
    Byte[1] = data & 0xFF;
    gpio_set_level(devspi->pin_dc, 1); // 发送数据，dc管脚设置1

    bool flag = spi_write_byte(devspi, Byte, 2);
    assert(flag == true);

    return true;
}

bool spi_write_data_words(DevSPI_t *devspi, const uint16_t *datas, int len)
{
    gpio_set_level(devspi->pin_dc, 1); // 发送数据，dc管脚设置1
    uint8_t Byte[1024] = {0};
    int index = 0;
    for (int j = 0; j < len; j++)
    {
        // 16位，分2个字节发送
        uint16_t data = *datas;
        Byte[index++] = (data >> 8) & 0xFF;
        Byte[index++] = data & 0xFF;
        datas++;
    }
    bool flag = spi_write_byte(devspi, Byte, len * 2); // 按字节发送后需要翻倍
    assert(flag == true);
    return true;
}