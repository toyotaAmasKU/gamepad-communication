# gamepad-communication

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
```
./main.elf <raspberri pi ip address> <x-axis port> <y-axis port>
```
may require superuser privileges

### How to include hidapi:
1. get [hidapi](https://github.com/signal11/hidapi)
2. install packages that required by hidapi
3. copy hidapi/hidapi/hid.h to include/
4. copy hidapi/linux/hid.c (hidapi/windows/hid.c if you are using Windows) to repository directory
