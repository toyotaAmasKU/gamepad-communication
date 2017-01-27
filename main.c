/*
 * Author: Natchanan Thongtem
 * Created on: 01/27/2017
 */

#include <stdio.h>

#include "hidapi.h"

int main(int argc, char *argv[])
{
    int response;

    response = hid_init();

    response = hid_exit();

    return 0;
}
