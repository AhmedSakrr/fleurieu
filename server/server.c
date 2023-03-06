#include "../fleurieu.h"
#include "server.h"

struct Server init_server(char* ip, int port) {
	struct Server server;

	server.ip = ip;
	server.port = port;
	
	memset(&server.addr, '\0', sizeof(server.addr));
	server.addr.sin_family = AF_INET;
	server.addr.sin_port = port;
	server.addr.sin_addr.s_addr = inet_addr(ip);

	server.socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server.socket < 0) {
		log_error("Error while creating socket.");
	} else {
		log_message("TCP server socket created.");
	}

	int n = bind(server.socket, (struct sockaddr*) &server.addr, sizeof(server.addr));
	if(n < 0) {
		log_error("Error while binding to port.");
	} else {
		log_message("Binded to port.");
	}

	return server;
}