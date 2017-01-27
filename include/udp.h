/*
 * Author: Natchanan Thongtem
 * Created on: 01/28/2017
 */

struct sockaddr_in init_socket_address(const char *ip_address, const int port);
void udp_send(int client_socket, char byte, struct sockaddr_in server);
