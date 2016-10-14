#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BACKLOG 5

int main()
{
    struct sockaddr_in infoServer;
    struct sockaddr_in retourServer;
    socklen_t tailleRetourServ;
    int retourSocket;
    int retourBind;
    int retourListen;
    int retourAccept;
    int retourRead;
    int retourWrite;
    int msg;

    infoServer.sin_family = AF_INET;
    infoServer.sin_addr.s_addr = htonl(INADDR_ANY);
    infoServer.sin_port = htons(5555);

    retourSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(retourSocket == -1)
    {
        printf("Erreur socket\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourBind = bind(retourSocket, (struct sockaddr *)&infoServer, sizeof(infoServer));

    if(retourBind == -1)
    {
        printf("Erreur bind\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourListen = listen(retourSocket, BACKLOG);

    if(retourListen == -1)
    {
        printf("Erreur listen\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    tailleRetourServ = sizeof(retourServer);
    retourAccept = accept(retourSocket, (struct sockaddr *)&retourServer, &tailleRetourServ);

    if(retourAccept == -1)
    {
        printf("Erreur accept\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourRead = read(retourAccept, &msg, sizeof(msg));

    if(retourRead == -1)
    {
        printf("Erreur recv\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    printf("%d", msg);
    msg = -msg;

    retourWrite = write(retourAccept, &msg, sizeof(msg));
    if(retourWrite == -1)
    {
        printf("Erreur sendto\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    return 0;
}
