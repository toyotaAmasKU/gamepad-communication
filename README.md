# gamepad-communication

### About:
##### Author:
###### [Natchanan Thongtem](https://github.com/psychoAB)
##### Description:
* gamepad communication using hidapi and send to raspberry pi

___

### How to build:
##### Linux
```
make
```
##### Windows
```
mingw32-make.exe
```

### How to use:
##### Linux
```
./main.elf <raspberri pi ip address> <x-axis port> <y-axis port>
```
may require superuser privileges.
##### Windows
```
main.elf <raspberri pi ip address> <x-axis port> <y-axis port>
```
may require superuser privileges.

### Required software:
1. [hidapi](https://github.com/signal11/hidapi)

### How to include hidapi:
1. get [hidapi](https://github.com/signal11/hidapi)
2. install packages that required by hidapi
3. copy hidapi/hidapi/hidapi.h to include/
4. copy hidapi/linux/hid.c (hidapi/windows/hid.c if you are using Windows) to repository directory
