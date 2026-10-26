# ESP8266-0S1环境搭建

vscode的espressidf工具，esp8266是没办法使用的，需要下面的环境进行构建

- 环境所在文件夹，E:\expressif-esp8266（目前已经换到E:\espressif-versions\expressif-esp8266）
- 首先从建项目先复制模板，E:\expressif-esp8266\ESP8266_RTOS_SDK\examples\get-started\hello_world，到E:\esp32_projects\esp826601s_alert
- 然后，双击打开，E:\expressif-esp8266\msys32\mingw32.exe
- 进入目录，E:\esp32_projects\esp826601s_alert
- 使用命令，make menuconfig，serial flasher config更改实际COM口，然后保存退出
- 使用命令，编译刷新，make flash monitor，最后就会烧录固件，并查打印串口信息
- 构建命令，make app

搭建参考：https://blog.csdn.net/weixin_44981971/article/details/126498753

参考本级目录：《2022 ESP8266_RTOS_SDK 开发环境搭建（VSCode）》

常见错误：

1、serial.serialutil.SerialException: Cannot configure port, something went wrong. Original message: PermissionError(13, '连到系统上的设备没有发挥作用。', None, 31)

打开设备管理 （Win+X快捷打开）-> 端口（COM和LTP）-> USB-SERIAL CH340 (COM46)

USB-SERIAL CH340版本太高3.9.2024.9，所以需要降下来，驱动版本降低到3.4，3.5左右即可，用esp32倒是可以用3.9.2024.9版本

驱动已经下载到E:\esp32\esp32 docs\CH341SER_3.5.zip
