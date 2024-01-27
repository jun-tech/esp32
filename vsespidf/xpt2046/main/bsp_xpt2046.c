#include "bsp_xpt2046.h"
#include "esp_system.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include <stddef.h>
#include <string.h>
#include "bsp_spi.h"

static const char *TAG = "bsp_xpt2046";

#define CMD_X_READ 0b10010000 // NOTE: XPT2046 data sheet says this is actually Y
#define CMD_Y_READ 0b11010000 // NOTE: XPT2046 data sheet says this is actually X
#define CMD_Z1_READ 0b10110000
#define CMD_Z2_READ 0b11000000

#define LV_HOR_RES 320
#define LV_VER_RES 480

/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
    TOUCH_NOT_DETECTED = 0,
    TOUCH_DETECTED = 1,
} xpt2046_touch_detect_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static uint16_t XPT2046_CS_PIN = -1;
static uint16_t XPT2046_IRQ = 26;
static spi_device_handle_t tp2046_spi;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize the XPT2046
 */
void xpt2046_init(spi_host_device_t host, uint16_t pin_cs, uint16_t pen_irq)
{
    ESP_LOGI(TAG, "XPT2046 Initialization");
    XPT2046_CS_PIN = pin_cs;
    XPT2046_IRQ = pen_irq;
    ESP_LOGI(TAG, "CS=%d，PEN=%d", pin_cs, pen_irq);
    // xpt2040设备添加至总线
    spi_device_interface_config_t devcfg = {
        .clock_speed_hz = 1 * 1000 * 1000,
        .spics_io_num = pin_cs, // CS pin
        .queue_size = 7,
        .flags = SPI_DEVICE_NO_DUMMY,
    };
    esp_err_t ret;
    ret = spi_bus_add_device(host, &devcfg, &tp2046_spi);
    ESP_LOGI(TAG, "spi_bus_add_device=%d", ret);
    assert(ret == ESP_OK);
    // 配置触摸屏
    gpio_config_t irq_config = {
        .pin_bit_mask = BIT64(pen_irq),
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ret = gpio_config(&irq_config);
    assert(ret == ESP_OK);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static int xptGetit(int cmd)
{
    char rbuf[MAX_LEN];
    char wbuf[MAX_LEN];

    memset(wbuf, 0, sizeof(rbuf));
    memset(rbuf, 0, sizeof(rbuf));
    wbuf[0] = cmd;
    spi_transaction_t SPITransaction;
    esp_err_t ret;

    memset(&SPITransaction, 0, sizeof(spi_transaction_t));
    SPITransaction.length = MAX_LEN * 8;
    SPITransaction.tx_buffer = wbuf;
    SPITransaction.rx_buffer = rbuf;
#if 1
    ret = spi_device_transmit(tp2046_spi, &SPITransaction);
#else
    ret = spi_device_polling_transmit(tp2046_spi, &SPITransaction);
#endif
    assert(ret == ESP_OK);
    ESP_LOGD(TAG, "rbuf[0]=%02x rbuf[1]=%02x rbuf[2]=%02x", rbuf[0], rbuf[1], rbuf[2]);
    // 12bit Conversion
    // int pos = (rbuf[1]<<8)+rbuf[2];
    int pos = (rbuf[1] << 4) + (rbuf[2] >> 4);
    return (pos);
}

bool xpt2046_read()
{
    uint8_t irq = gpio_get_level(XPT2046_IRQ);
    // ESP_LOGI(TAG, "gpio_get_level=%d", irq);
    if (irq != 0)
    {
        return false;
    }
    int xp = xptGetit(XPT_START | XPT_XPOS | XPT_SER);
    int yp = xptGetit(XPT_START | XPT_YPOS | XPT_SER);
    ESP_LOGI(TAG, "xp=%d，yp=%d", xp, yp);
    return true;
}
