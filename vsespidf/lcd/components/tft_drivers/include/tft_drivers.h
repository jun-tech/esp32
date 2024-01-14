#ifndef TFT_DRIVERS_H
#define TFT_DRIVERS_H
#include "spi_mgr.h"

// 颜色
#define rgb565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3))
#define RED rgb565(255, 0, 0)       // 0xf800
#define GREEN rgb565(0, 255, 0)     // 0x07e0
#define BLUE rgb565(0, 0, 255)      // 0x001f
#define BLACK rgb565(0, 0, 0)       // 0x0000
#define WHITE rgb565(255, 255, 255) // 0xffff
#define GRAY rgb565(128, 128, 128)  // 0x8410
#define YELLOW rgb565(255, 255, 0)  // 0xFFE0
#define CYAN rgb565(0, 156, 209)    // 0x04FA
#define PURPLE rgb565(128, 0, 128)  // 0x8010

// 屏幕宽高
#define TFT_WIDTH 320
#define TFT_HEIGHT 480

typedef enum
{
    DIRECTION0,
    DIRECTION90,
    DIRECTION180,
    DIRECTION270
} DIRECTION;

typedef struct tft_dev
{
    DevSPI_t devspi;
    uint16_t model; // 将来扩展，目前只支持st77796
    int width;
    int height;
    int offsetx;
    int offsety;
    DIRECTION direction;

    // 管脚
    int pincs;
    int pinrst;
    int pinbckl;

} TFTDev_t;

void tftInit(TFTDev_t *dev);
void tftSetBackLight(unsigned char duty); // 设置占空比0~256
void tftSetWindow(TFTDev_t *dev, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void tftSetDirection(TFTDev_t *dev, DIRECTION direct);
void tftClear(TFTDev_t *dev, uint16_t color);

#endif