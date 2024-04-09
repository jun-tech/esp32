# 搭建教程

https://zhuanlan.zhihu.com/p/630698425



# 例子说明

| 目录    | idf   | 中文描述                                                     |
| ------- | ----- | ------------------------------------------------------------ |
| lvgl    | 5.1.2 | 官方例子，spi协议集成lvgl，sdcard，xpt2046，st7796屏幕       |
| lcd     | 4.4.5 | 个人编写驱动理解项目，spi协议集成lvgl                        |
| lcd_i80 | 4.4.5 | 8080，16位并口，引用博主https://yuanze.wang/posts/lvgl-on-esp32s3/，感谢。8位并口转接板0欧姆电阻r4换到r5位，低8位。io1、io3是串口打印，并口时不使用此接口，不然乱码。 |

# 外设接线



| 外设        | ESP32                                           | ESPS3                                                        |
| ----------- | ----------------------------------------------- | ------------------------------------------------------------ |
| **TFT屏幕** |                                                 |                                                              |
| RS/DC       | IO15                                            | IO4                                                          |
| CS          | IO2                                             | IO5                                                          |
| RD          | IO16不接线也不影响                              | NC 、IO6不接线                                               |
| WR          | IO4                                             | IO7                                                          |
| RST         | IO17                                            | IO15                                                         |
| BL背光灯    | IO3，或3v3                                      | IO16                                                         |
| DB0         | IO32                                            | IO17                                                         |
| DB1         | IO33                                            | IO18                                                         |
| DB2         | IO25                                            | IO8                                                          |
| DB3         | IO26                                            | IO9                                                          |
| DB4         | IO27                                            | IO10                                                         |
| DB5         | IO14                                            | IO11                                                         |
| DB6         | IO12                                            | IO12                                                         |
| DB7         | IO13                                            | IO13                                                         |
| DB8-DB15    |                                                 | IO21（8）, 47（9）, 48（10）, **<u>46（11）</u>/<u>20（11）</u>**, 40（12）/<u>**19（12）**</u>, 6（13）, 38（14）, <u>**0（15）**</u>，注意：20，19为jtag调试引脚，占用后无法调试，支持PSRAM |
|             |                                                 | IO21（8）, 47（9）, 48（10）, **<u>35（11）, 36（12）, 37（13）</u>**, 38（14）, 6（15），注意：开启PSRAM时，35、36、37不可用 |
| **电阻笔**  |                                                 |                                                              |
| TSDI        | **IO23（VSPI）MOSI**                            | **IO1（VSPI）MOSI**                                          |
| TSDO        | **IO19（VSPI）MISO**                            | **IO2（VSPI）MISO**                                          |
| TPEN        | IO21                                            | IO14                                                         |
| TCLK        | **IO18（VSPI）SCK**                             | **IO42（VSPI）SCK**                                          |
| TCS         | IO22                                            | IO41                                                         |
| **SDCARD**  | 共用VSPI，也叫SPI3                              |                                                              |
| CS          | IO5                                             | IO39                                                         |
| MOSI        | **IO23（VSPI）**                                | **IO1（VSPI）MOSI**                                          |
| MISO        | **IO19（VSPI）** 原打算用GPIO12，发现跟boot冲突 | **IO2（VSPI）MISO**                                          |
| SCK         | **IO18（VSPI）**                                | **IO42（VSPI）SCK**                                          |

