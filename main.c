/*
 * Author: Natchanan Thongtem
 * Created on: 01/27/2017
 */

#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "hidapi.h"

#define MAX_STR 255
#define BUFFER_SIZE 65

#define LOGITECT_VID 0x046d
#define GAMEPAD_PID 0xc219

#define LEFT_ANALOG_X_AXIS 1
#define LEFT_ANALOG_Y_AXIS 2
#define RIGHT_ANALOG_X_AXIS 3
#define RIGHT_ANALOG_Y_AXIS 4
#define MAGIC_NUMBER_FOR_GAMEPAD 128

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
    wchar_t wstr[MAX_STR];
    unsigned char buffer[BUFFER_SIZE];
    int response;

    response = hid_init();
    handle = hid_open(LOGITECT_VID, GAMEPAD_PID, NULL);

    response = hid_get_manufacturer_string(handle, wstr, MAX_STR);
    printf("%ls\n", wstr);

    response = hid_get_product_string(handle, wstr, MAX_STR);
    printf("%ls\n", wstr);

    hid_set_nonblocking(handle, 1);

    struct sockaddr_in server_x, server_y;
    socklen_t address_size_x, address_size_y;
    int client_socket_x, client_socket_y;

    client_socket_x = socket(PF_INET, SOCK_DGRAM, 0);
    client_socket_y = socket(PF_INET, SOCK_DGRAM, 0);

    server_x.sin_family = AF_INET;
    server_x.sin_port = htons(x_axis_port);
    server_x.sin_addr.s_addr = inet_addr(rpi_ip);
    memset(server_x.sin_zero, '\0', sizeof(server_x.sin_zero));

    server_y.sin_family = AF_INET;
    server_y.sin_port = htons(y_axis_port);
    server_y.sin_addr.s_addr = inet_addr(rpi_ip);
    memset(server_y.sin_zero, '\0', sizeof(server_y.sin_zero));

    address_size_x = sizeof(server_x);
    address_size_y = sizeof(server_y);

    while(1)
    {
        response = 0;
        response = hid_read(handle, buffer, BUFFER_SIZE);

        int i;
        for(i = 0; i < response; i++)
        {
            printf("%02hhx ", buffer[i]);
        }
        printf("\n");

        signed char x, y;

        x = buffer[LEFT_ANALOG_X_AXIS] - MAGIC_NUMBER_FOR_GAMEPAD;
        y = buffer[RIGHT_ANALOG_Y_AXIS] - MAGIC_NUMBER_FOR_GAMEPAD;
        y += 1;
        y *= -1;

        printf("x = %d  y = %d\n", x, y);

        sendto(client_socket_x, &x, sizeof(x), 0, (struct sockaddr *)&server_x, address_size_x);
        sendto(client_socket_y, &y, sizeof(y), 0, (struct sockaddr *)&server_y, address_size_y);
    }

    hid_close(handle);
    response = hid_exit();

    return 0;
}
