/*
 * Author: Natchanan Thongtem
 * Created on: 01/27/2017
 */

#include <stdio.h>

#include "hidapi.h"

#define MAX_STR 255
#define BUFFER_SIZE 65

#define LOGITECT_VID 0x046d
#define GAMEPAD_PID 0xc219

int main(int argc, char *argv[])
{
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
    }

    hid_close(handle);
    response = hid_exit();

    return 0;
}
