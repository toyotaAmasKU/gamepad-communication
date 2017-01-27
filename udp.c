/*
 * Author: Natchanan Thongtem
 * Created on: 01/28/2017
 */

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
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
    socklen_t address_size;

    address_size = sizeof(server);

    sendto(client_socket, &byte, sizeof(byte), 0, (struct sockaddr *)&server, address_size);
}