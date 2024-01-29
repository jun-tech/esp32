# 搭建教程

https://zhuanlan.zhihu.com/p/630698425



# 例子说明

| 目录    | idf   | 中文描述                                                     |
| ------- | ----- | ------------------------------------------------------------ |
| lvgl    | 5.1.2 | 官方例子，spi协议集成lvgl，sdcard，xpt2046，st7796屏幕       |
| lcd     | 4.4.5 | 个人编写驱动理解项目，spi协议集成lvgl                        |
| lcd_i80 | 4.4.5 | 8080，16位并口，引用博主https://yuanze.wang/posts/lvgl-on-esp32s3/，感谢。8位并口转接板0欧姆电阻r4换到r5位，低8位。io1、io3是串口打印，并口时不使用此接口，不然乱码。 |

# 外设接线

| 外设        | ESP32                                           | ESPC3 |
| ----------- | ----------------------------------------------- | ----- |
| **TFT屏幕** |                                                 |       |
| RS/DC       | IO15                                            |       |
| CS          | IO2                                             |       |
| RD          | IO16不接线也不影响                              |       |
| WR          | IO4                                             |       |
| RST         | IO17                                            |       |
| BL背光灯    | IO3，或3v3                                      |       |
| DB0         | IO32                                            |       |
| DB1         | IO33                                            |       |
| DB2         | IO25                                            |       |
| DB3         | IO26                                            |       |
| DB4         | IO27                                            |       |
| DB5         | IO14                                            |       |
| DB6         | IO12                                            |       |
| DB7         | IO13                                            |       |
| **电阻笔**  |                                                 |       |
| TSDI        | **IO23（VSPI）MOSI**                            |       |
| TSDO        | **IO19（VSPI）MISO**                            |       |
| TPEN        | IO21                                            |       |
| TCLK        | **IO18（VSPI）SCK**                             |       |
| TCS         | IO22                                            |       |
| **SDCARD**  | 共用VSPI，也叫SPI3                              |       |
| CS          | IO5                                             |       |
| MOSI        | **IO23（VSPI）**                                |       |
| MISO        | **IO19（VSPI）** 原打算用GPIO12，发现跟boot冲突 |       |
| SCK         | **IO18（VSPI）**                                |       |

