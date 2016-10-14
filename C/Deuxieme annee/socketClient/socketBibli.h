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

#define LONGCHAR 512

void mort(char *cituation);
int connection(struct sockaddr_in *infoServeur);
void dialogueInt(int retourSocket, struct sockaddr_in *infoServeur);
void dialogueChar(int retourSocket, struct sockaddr_in *infoServeur);
void dialogueFloat(int retourSocket, struct sockaddr_in *infoServeur);

#endif // SOCKETBIBLI_H_INCLUDED
