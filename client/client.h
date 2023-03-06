#ifndef CLIENT_H
#define CLIENT_H

#include "../fleurieu.h"

struct Client {
	char* ip;
	int port;
	int socket;
	struct sockaddr_in addr;
	char buffer[1024];
};

struct Client init_client(char* ip, int port);

#endif