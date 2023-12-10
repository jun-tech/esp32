#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#include "my_img.h"

TFT_eSPI tft = TFT_eSPI();           /* TFT instance */
TFT_eSprite spr = TFT_eSprite(&tft); // 局部刷新

int i = 0;
int n = 0;

static void displaySomething();

void setup()
{
  Serial.begin(115200); /* prepare for possible serial debug */
  tft.begin();          /* TFT init */
  tft.setRotation(1);   /* Landscape orientation */
  // 显示图片
  tft.setSwapBytes(true);
  tft.pushImage(0, 0, 240, 240, gImage_my_img);
  delay(5000);
  tft.fillScreen(TFT_WHITE);
  // 打印屏配置宽高
  Serial.printf("w: %d, h: %d \r\n", tft.width(), tft.height());
}

void displaySomething()
{
  // 清屏
  tft.fillScreen(TFT_BLACK);
  // 窗体
  spr.createSprite(100, 100); // 创建窗体
  spr.fillSprite(TFT_BLACK);
  spr.drawLine(0, 0, 100, 100, TFT_GREEN);
  spr.drawLine(0, 100, 100, 0, TFT_RED);
  // 在中间写一些字
  char myStr[200] = {0};
  sprintf(myStr, "Hello %d", n);

  spr.setTextDatum(MC_DATUM);
  spr.drawString(myStr, 100 / 2, 100 / 2, 4);

  // 绘制
  spr.pushSprite(n, n); // 显示位置

  // 释放窗体，释放内存
  spr.deleteSprite();

  i++;
  n++;
  if (n > 140)
    n = 0;
  delay(10);
}

void loop()
{
  // 窗体上显示一些东西
  displaySomething();
  delay(5);
}