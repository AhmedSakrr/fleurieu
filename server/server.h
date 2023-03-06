#ifndef SERVER_H
#define SERVER_H

#include "../fleurieu.h"

struct Server {
	char* ip;
	int port;
	int socket;
	struct sockaddr_in addr;
	char buffer[1024];
};

struct Server init_server(char* ip, int port);

#endif