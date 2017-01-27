CFLAGS=-Wall -Iinclude/
OBJS=hid.o

LIBS_UDEV=`pkg-config libudev --libs` -lrt

main.elf: $(OBJS) main.o
	gcc $(CFLAGS) $^ $(LIBS_UDEV) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	-rm *.o main.elf
