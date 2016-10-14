#ifndef SOCKETBIBLI_H_INCLUDED
#define SOCKETBIBLI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define CHARLEN 512

void mort(char *cituation);
int demarrage();
void dialogueInt(int socket);
void dialogueChar(int socket);
void dialogueFloat(int socket);

#endif // SOCKETBIBLI_H_INCLUDED
