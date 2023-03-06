#include "fleurieu.h"

int main() {
	char* ip = "127.0.0.1"; //IP of server
	int port = 9999; //Port for server to run on

	int server_sock, client_sock;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;

	server_sock = socket(AF_INET, SOCK_STREAM, 0);

	if(server_sock < 0) {
		log_error("Error while creating socket.");
	} else {
		log_message("TCP server socket created.");
	}

	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(ip);

	n = bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr));
	if(n < 0) {
		log_error("Error while binding to port.");
	} else {
		log_message("Binded to port.");
	}

	listen(server_sock, 5);
	log_message("Waiting for client.");

	while(1) {
		addr_size = sizeof(client_addr);
		client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
		log_message("Client connected.");

	}


	return 0;
}