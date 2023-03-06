#include "../fleurieu.h"
#include "client.h"

struct Client init_client(char* ip, int port) {
	struct Client client;

	client.ip = ip;
	client.port = port;
	
	memset(&client.addr, '\0', sizeof(client.addr));
	client.addr.sin_family = AF_INET;
	client.addr.sin_port = port;
	client.addr.sin_addr.s_addr = inet_addr(ip);

	client.socket = socket(AF_INET, SOCK_STREAM, 0);
	if(client.socket < 0) {
		log_error("Error while creating socket.");
	} else {
		log_message("TCP server socket created.");
	}

	return client;
}
