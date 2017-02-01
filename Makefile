# 
# Author: Natchanan Thongtem
# Created on: 01/28/2017
#

CFLAGS=-Wall -Iinclude/
OBJS=hid.o udp.o

ifeq ($(OS),Windows_NT)
	LIBS=-lsetupapi -lws2_32
else
	LIBS=`pkg-config libudev --libs` -lrt
endif

main.elf: $(OBJS) main.o
	gcc $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	-rm *.o main.elf
