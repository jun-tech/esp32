#ifndef BSP_SPI_H
#define BSP_SPI_H

#include <stdint.h>
#include "driver/spi_master.h"

void bsp_spi_bus_init(spi_host_device_t host, uint16_t pin_miso, uint16_t pin_mosi, uint16_t pin_sclk);
void bsp_spi_add_device(spi_host_device_t host, spi_device_interface_config_t *devcfg);
void bsp_spi_read_reg(uint8_t reg, uint8_t *data, uint8_t byte_count);

#endif