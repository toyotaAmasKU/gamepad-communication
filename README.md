# gamepad-communication

##### Author:
###### [Natchanan Thongtem](https://github.com/psychoAB)
##### Description:
###### gamepad communication using hidapi and send to raspberry pi
___

### Requirement:
1. [hidapi](https://github.com/signal11/hidapi)

### How to build:
##### Linux
```bash
make
```
##### Windows
```
mingw32-make.exe
```

### How to use:
##### Linux
```bash
./main.elf <RASPBERRY_PI_IP_ADDRESS> <X_AXIS_PORT> <Y_AXIS_PORT>
```
may require superuser privilege.
##### Windows
```
main.elf <RASPBERRY_PI_IP_ADDRESS> <X_AXIS_PORT> <Y_AXIS_PORT>
```
may require superuser privilege.

### How to include hidapi:
1. get [hidapi](https://github.com/signal11/hidapi)
2. install packages that required by hidapi
3. copy __hidapi/hidapi/hidapi.h__ to __include/__
4. copy __hidapi/linux/hid.c__ (__hidapi/windows/hid.c__ if you are using Windows) to __repository directory__
