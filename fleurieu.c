#include "fleurieu.h"

void log_message(char* message) {
	printf("[+] - %s\n", message);
	return;
}

void log_error(char* message) {
	printf("[*] - %s\n", message);
	exit(1);
	return;
}

void send_message(char* message,  int socket) {
	send(socket, message, strlen(message), 0);
}

void recieve_message(int socket, char* buffer) {
	bzero(buffer, 1024);
	recv(socket, buffer, sizeof(char) * 1024, 0);
}