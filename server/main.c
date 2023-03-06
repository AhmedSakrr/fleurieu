#include "../fleurieu.h"
#include "../client/client.h"
#include "server.h"

int main() {
	struct Server server = init_server("127.0.0.1", 9999);

	listen(server.socket, 5);
	log_message("Waiting for client.");

	socklen_t addr_size;
	int client_sock;
	struct sockaddr_in client_addr;

	while(1) {
		addr_size = sizeof(client_addr);
		client_sock = accept(server.socket, (struct sockaddr*)&client_addr, &addr_size);
		log_message("Client connected.");

		recieve_message(client_sock, server.buffer);
		log_message(server.buffer);

		send_message("129.85.193.51", client_sock);
	}

	return 0;
}

