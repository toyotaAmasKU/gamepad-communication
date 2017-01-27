/*
 * Author: Natchanan Thongtem
 * Created on: 01/27/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>

#include "hidapi.h"
#include "gamepad.h"

#include "udp.h"

#define BUFFER_SIZE 65

#define SAMPLE_TIME 0.01

#define MEGA 1000000

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        return 1;
    }
    const char *rpi_ip = argv[1];
    const int x_axis_port = atoi(argv[2]);
    const int y_axis_port  = atoi(argv[3]);

    hid_device *handle;
    unsigned char buffer[BUFFER_SIZE];
    int response;

    response = hid_init();
    handle = hid_open(LOGITECT_VID, GAMEPAD_PID, NULL);

    hid_set_nonblocking(handle, 1);

    struct sockaddr_in server_x, server_y;
    int client_socket_x, client_socket_y;

    client_socket_x = socket(PF_INET, SOCK_DGRAM, 0);
    client_socket_y = socket(PF_INET, SOCK_DGRAM, 0);

    server_x = init_socket_address(rpi_ip, x_axis_port);
    server_y = init_socket_address(rpi_ip, y_axis_port);

    while(1)
    {
        response = 0;
        response = hid_read(handle, buffer, BUFFER_SIZE);

        signed char x, y;

        x = buffer[LEFT_ANALOG_X_AXIS] - MAGIC_NUMBER_FOR_GAMEPAD;
        y = buffer[RIGHT_ANALOG_Y_AXIS] - MAGIC_NUMBER_FOR_GAMEPAD;
        y += 1;
        y *= -1;

        printf("x = %d  y = %d\n", x, y);

        udp_send(client_socket_x, x, server_x);
        udp_send(client_socket_y, y, server_y);

        usleep(SAMPLE_TIME * MEGA);
    }

    hid_close(handle);
    response = hid_exit();

    return 0;
}
