#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <lvgl.h>
#include <XPT2046_Touchscreen.h>

/*To use the built-in examples and demos of LVGL uncomment the includes below respectively.
 *You also need to copy `lvgl/examples` to `lvgl/src/examples`. Similarly for the demos `lvgl/demos` to `lvgl/src/demos`.
 Note that the `lv_examples` library is for LVGL v7 and you shouldn't install it for this version (since LVGL v8)
 as the examples and demos are now part of the main LVGL library. */

// #include <examples/lv_examples.h>
#include <demos/lv_demos.h>

/*Change to your screen resolution*/
static const uint16_t screenWidth = TFT_WIDTH;
static const uint16_t screenHeight = TFT_HEIGHT;

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */
XPT2046_Touchscreen ts(TOUCH_CS);                   // Param 2 - NULL - No interrupts

void touch_xpt2046_init(void)
{
  ts.begin();
  ts.setRotation(3);
}

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf)
{
  Serial.printf(buf);
  Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  // 非DMA渲染
  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  tft.pushColors((uint16_t *)&color_p->full, w * h, true);
  tft.endWrite();
  // DMA渲染 begin
  // tft.startWrite();
  // tft.setSwapBytes(true); // LV_COLOR_16_SWAP 也可以在这里设为1，此行就可以注释掉
  // tft.pushPixelsDMA((uint16_t *)&color_p->full, w * h);
  // // tft.pushImageDMA(area->x1, area->y1, w, h, (uint16_t *)&color_p->full);
  // // tft.dmaWait();
  // tft.endWrite();
  // DMA渲染 end
  lv_disp_flush_ready(disp_drv);
}

uint16_t rawPointMinX = 168;
uint16_t rawPointMaxX = 3700;
uint16_t rawPointMinY = 378;
uint16_t rawPointMaxY = 3700;
uint16_t screenPointX;
uint16_t screenPointY;

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  if (ts.touched())
  {
    data->state = LV_INDEV_STATE_PR;
    TS_Point p = ts.getPoint();
    /*Set the coordinates*/

    screenPointX = screenWidth - screenWidth * (p.x - rawPointMinX) / (rawPointMaxX - rawPointMinX);
    screenPointY = screenHeight * (p.y - rawPointMinY) / (rawPointMaxY - rawPointMinY);

    data->point.x = screenPointX;
    data->point.y = screenPointY;
    // data->point.x = p.x;
    // data->point.y = p.y;

    Serial.print("touch x ");
    // Serial.print(p.x);
    Serial.print(screenPointX);

    Serial.print(", touch y \r\n");
    // Serial.println(p.y);
    Serial.print(screenPointY);
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
}

void setup()
{
  // 超频测试
  // 300MHz需要调压，如果270MHz不需要加这句
  // vreg_set_voltage(VREG_VOLTAGE_1_30);
  // set_sys_clock_khz(PLL_SYS_KHZ, true);

  Serial.begin(115200); /* prepare for possible serial debug */

  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.println(LVGL_Arduino);
  Serial.println("I am LVGL_Arduino");

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  tft.begin();        /* TFT init */
  tft.setRotation(1); /* Landscape orientation, flipped */
  tft.initDMA();

  //   /*Set the touchscreen calibration data,
  //    the actual data for your display can be acquired using
  //    the Generic -> Touch_calibrate example from the TFT_eSPI library*/
  // uint16_t calData[5] = {275, 3620, 264, 3532, 1};
  // tft.setTouch(calData);
  touch_xpt2046_init();

  /*Create a display buffer*/
  // 单buffer除10相当于分10等分刷新全屏
  // static lv_disp_draw_buf_t draw_buf;
  // static lv_color_t buf[screenWidth * screenHeight / 10];
  // lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

  // 非全尺寸双buffer 内存不够
  // static lv_disp_draw_buf_t draw_buf_dsc_2;                                                           // 两个半屏缓存
  // static lv_color_t draw_buf_2_1[screenWidth * screenHeight / 2];                                     /*A buffer for 10 rows*/
  // static lv_color_t draw_buf_2_2[screenWidth * screenHeight / 2];                                     /*An other buffer for 10 rows*/
  // lv_disp_draw_buf_init(&draw_buf_dsc_2, draw_buf_2_2, draw_buf_2_1, screenWidth * screenHeight / 2); /*Initialize the display buffer*/

  // 双缓冲
  static lv_disp_draw_buf_t draw_buf;
  static lv_color_t draw_buf_2_1[screenWidth * 15];
  static lv_color_t draw_buf_2_2[screenWidth * 15];
  lv_disp_draw_buf_init(&draw_buf, draw_buf_2_2, draw_buf_2_1, screenWidth * 15);

  // 一次刷新
  // 全尺寸双buffer 内存不够
  // static lv_disp_draw_buf_t draw_buf_dsc_2;                                                       // 两个全屏缓存
  // static lv_color_t draw_buf_2_1[screenWidth * screenHeight];                                     /*A buffer for 10 rows*/
  // static lv_color_t draw_buf_2_2[screenWidth * screenHeight];                                     /*An other buffer for 10 rows*/
  // lv_disp_draw_buf_init(&draw_buf_dsc_2, draw_buf_2_2, draw_buf_2_1, screenWidth * screenHeight); /*Initialize the display buffer*/

  /*Create a display*/
  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;  // 水平
  disp_drv.ver_res = screenHeight; // 垂直
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  disp_drv.antialiasing = 1;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  /* Create simple label */
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Hello Ardino and LVGL!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  /* Try an example. See all the examples
   * online: https://docs.lvgl.io/master/examples.html
   * source codes: https://github.com/lvgl/lvgl/tree/e7f88efa5853128bf871dde335c0ca8da9eb7731/examples */
  // lv_example_btn_1();

  /*Or try out a demo. Don't forget to enable the demos in lv_conf.h. E.g. LV_USE_DEMOS_WIDGETS*/
  // lv_demo_widgets();
  // lv_demo_keypad_encoder();
  // lv_demo_music();
  // lv_demo_printer();
  // 以下2案例性能测试
  lv_demo_benchmark();
  // lv_demo_stress();

  Serial.println("Setup done");
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  // lv_tick_inc(5);     // 注释掉lvgl刷新 使用lv_conf.h 打开LV_TICK_CUSTOM，fps统计才有效
  delay(5);
}
