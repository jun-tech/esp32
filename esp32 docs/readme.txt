https://www.altium.com/viewer/cn/
在线查看原理图

非常好的学习资源
https://yuanze.wang/posts/

扩展板
https://yuanze.wang/posts/esp32-expansion-board/

下载器
https://yuanze.wang/posts/esp32-flasher/


ESP32-S3
不建议使用的管脚（GPIO）
用于与封装内 flash/PSRAM 通讯，不建议作其他用途。

管脚	功能
GPIO 26	SPICS1
GPIO 27	SPIHD
GPIO 28	SPIWP
GPIO 29	SPICS0
GPIO 30	SPICLK
GPIO 31	SPIQ
GPIO 32	SPID

受限制使用的管脚（GPIO）
一般具有重要功能，按需求调整使用。

管脚	功能
GPIO 0	芯片启动模式
GPIO 3	JTAG 信号源
GPIO 19	UART 接口 – 通常用于调试功能。
GPIO 20	UART 接口 – 通常用于调试功能。
GPIO 45	VDD_SPI 电压
GPIO 46	芯片启动模式/ROM 代码日志打印
GPIO 35   开启PSRAM时不能占用
GPIO 36   开启PSRAM时不能占用
GPIO 37   开启PSRAM时不能占用