#include "bsp_spi.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char *TAG = "bsp_spi";

static spi_device_handle_t spi;

void bsp_spi_bus_init(spi_host_device_t host, uint16_t pin_miso, uint16_t pin_mosi, uint16_t pin_sclk)
{
    esp_err_t ret;

    ESP_LOGI(TAG, "MISO=%d", pin_miso);
    ESP_LOGI(TAG, "MOSI=%d", pin_mosi);
    ESP_LOGI(TAG, "SCLK=%d", pin_sclk);

    spi_bus_config_t buscfg = {
        .miso_io_num = pin_miso,
        .mosi_io_num = pin_mosi,
        .sclk_io_num = pin_sclk,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = 81920};
    ret = spi_bus_initialize(host, &buscfg, SPI_DMA_CH_AUTO);
    ESP_LOGI(TAG, "spi_bus_initialize ret=%d SPI_HOST=%d", ret, host);
    assert(ret == ESP_OK);
}

void bsp_spi_add_device(spi_host_device_t host, spi_device_interface_config_t *devcfg)
{
    esp_err_t ret;
    ret = spi_bus_add_device(host, devcfg, &spi);
    ESP_LOGI(TAG, "spi_bus_add_device=%d", ret);
    assert(ret == ESP_OK);
}

void bsp_spi_read_reg(uint8_t reg, uint8_t *data, uint8_t byte_count)
{
    spi_transaction_t t = {
        .length = (byte_count + sizeof(reg)) * 8,
        .rxlength = byte_count * 8,
        .cmd = reg,
        .rx_buffer = data,
        .flags = 0};

    // Read - send first byte as command
    esp_err_t ret = spi_device_transmit(spi, &t);
    assert(ret == ESP_OK);
}