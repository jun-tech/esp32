# 工程搭建

ESP32C3合宙版，搭建详情基于本级目录lvgl，其他差别参考此文档



# 接线配置

|     TFT     | ESP32-C2/C3 |
| :---------: | :---------: |
|     VCC     |     3V3     |
|     GND     |     GND     |
|     CS      |    GPIO7    |
|    REST     |   GPIO11    |
|     D/C     |    GPIO6    |
|    MOSI     |  **GPIO3**  |
|     SCK     |  **GPIO2**  |
| LED（背光） | 3.3V/GPIO5  |
|    MISO     |     N/C     |
|    T_CLK    |  **GPIO2**  |
|    T_CS     |    GPIO4    |
|    T_DIN    | **GPIO03**  |
|    T_OUT    |   GPIO10    |
|    T_IRQ    |    GPIO8    |

Swap XY.选项去掉打勾	Invert X coordinate value.选项去掉打勾	Invert Y coordinate value.选项打勾

