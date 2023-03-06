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