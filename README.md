# gamepad-communication

### How to build:
```
make
```

### How to use:
```
sudo ./main.elf <raspberri pi ip address> <x-axis port> <y-axis port>
```

### How to include hidapi:
1. get [hidapi](https://github.com/signal11/hidapi)
2. install packages that required by hidapi
2. copy hidapi/hidapi/hid.h to include/
3. copy hidapi/linux/hid.c to repository directory 
