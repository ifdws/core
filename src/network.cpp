#include "network.hpp"

int server_fd, new_socket, valread;
struct sockaddr_in address;
int addrlen = sizeof(address);

char buffer[1024] = { 0 };

void network_init(int port) {
	int opt = 1;
	
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket() failed!");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		perror("setsockopt() failed!");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("Failed to bind!");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
		perror("Failed to listen!");
		exit(EXIT_FAILURE);
	}
}

void accept_connection() {
	if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
		perror("Failed to accept connection!");
		exit(EXIT_FAILURE);
	}
}

string read_data() {
	valread = read(new_socket, buffer, 1024);
	string data = buffer;

	return data;
}

void send_data(string data) {
	send(new_socket, data.c_str(), strlen(data.c_str()), 0);
}

void close_socket() {
	close(new_socket);
}

void close_server() {
	shutdown(server_fd, SHUT_RDWR);
}