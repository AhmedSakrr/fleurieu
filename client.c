#include "fleurieu.h"

int main() {
	char* ip = "127.0.0.1";
	int port = 9999;

	int sock;
	struct sockaddr_in addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;

	sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0) {
		log_error("Error while creating socket.");
	} else {
		log_message("TCP server socket created.");
	}

	memset(&addr, '\0', sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);

	connect(sock, (struct sockaddr*)&addr, sizeof(addr));
	log_message("Connected to server.");
	return 0;
}