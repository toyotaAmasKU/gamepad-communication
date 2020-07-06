/*
    Copyright (C) 2017  Natchanan Thongtem

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef _WIN32
    #include <winsock2.h>
#else
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
#endif

#include <string.h>

struct sockaddr_in init_socket_address(const char *ip_address, const int port)
{
    struct sockaddr_in server;
    
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip_address);
    memset(server.sin_zero, '\0', sizeof(server.sin_zero));

    return server;
}

void udp_send(int client_socket, char byte, struct sockaddr_in server)
{
    #ifdef WIN32
        int address_size;
    #else
        socklen_t address_size;
    #endif

    address_size = sizeof(server);

    sendto(client_socket, &byte, sizeof(byte), 0, (struct sockaddr *)&server, address_size);
}
