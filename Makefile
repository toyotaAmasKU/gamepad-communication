#   Copyright (C) 2017  Natchanan Thongtem
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#   
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
