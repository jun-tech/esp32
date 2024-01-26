#ifndef BSP_SPI_H
#define BSP_SPI_H

#include <stdint.h>
#include "driver/spi_master.h"

void bsp_spi_bus_init(spi_host_device_t host, uint16_t pin_miso, uint16_t pin_mosi, uint16_t pin_sclk);
void bsp_spi_add_device(spi_host_device_t host, uint32_t clock_speed_hz, uint16_t pin_cs);
// void tp_spi_add_device_config(spi_host_device_t host, spi_device_interface_config_t *config);
// void tp_spi_xchg(uint8_t *data_send, uint8_t *data_recv, uint8_t byte_count);
// void tp_spi_write_reg(uint8_t *data, uint8_t byte_count);
void bsp_spi_read_reg(uint8_t reg, uint8_t *data, uint8_t byte_count);

#endif