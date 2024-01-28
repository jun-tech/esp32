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
| RS/DC       | IO2                                             |       |
| CS          | IO4                                             |       |
| RD          | 不接线也不影响                                  |       |
| WR          | IO16                                            |       |
| RST         | IO17                                            |       |
| BL背光灯    | IO15，或3v3                                     |       |
| DB0         | IO5                                             |       |
| DB1         | IO18                                            |       |
| DB2         | IO19                                            |       |
| DB3         | IO21                                            |       |
| DB4         | IO33                                            |       |
| DB5         | IO32                                            |       |
| DB6         | IO22                                            |       |
| DB7         | IO23                                            |       |
| **电阻笔**  |                                                 |       |
| TSDI        | **IO13（HSPI）MOSI**                            |       |
| TSDO        | **IO26（HSPI）MISO**                            |       |
| TPEN        | IO35                                            |       |
| TCLK        | **IO14（HSPI）SCK**                             |       |
| TCS         | IO25                                            |       |
| **SDCARD**  | 共用HSPI，也叫SPI2                              |       |
| CS          | IO27                                            |       |
| MOSI        | **IO13（HSPI）**                                |       |
| MISO        | **IO26（HSPI）** 原打算用GPIO12，发现跟boot冲突 |       |
| SCK         | **IO14（HSPI）**                                |       |

