#ifndef FLEURIEU_H
#define FLEURIEU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void log_message(char* message);
void log_error(char* message);
void send_message(char* message, int socket);
void recieve_message(int socket, char* buffer);

#endif