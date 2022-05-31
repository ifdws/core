#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;

void network_init(int port);
void accept_connection();
string read_data();
void send_data(string data);
void close_socket();
void close_server();