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
#define MAX 512

int main()
{

    fd_set rfds;
    struct timeval tv;

    struct sockaddr_in infoServer;
    struct sockaddr_in retourServer;
    socklen_t tailleInfoServ;
    int retourSocket;
    int retourBind;
    int retourListen;
    int retourAccept;
    int retourRead;
    int retourWrite;
    char msg[MAX];

    infoServer.sin_family = AF_INET;
    infoServer.sin_addr.s_addr = htonl(INADDR_ANY);
    infoServer.sin_port = htons(3434);

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

    printf("Attente d'une connexion.\n\n");

    tailleInfoServ = sizeof(retourServer);
    retourAccept = accept(retourSocket, (struct sockaddr *)&retourServer, &tailleInfoServ);
    if(retourAccept == -1)
    {
        printf("Erreur accept\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    while(1)
    {
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        printf("Attente d'un nouveau message...\n\n");

        if(select(retourSocket+1, &rfds, NULL, NULL, &tv))
        {
            retourRead = read(retourAccept, &msg, sizeof(msg));
            if(retourRead == -1)
            {
                printf("Erreur read\n");
                printf("%s", strerror(errno));
                exit(errno);
            }

            printf("Nouveau message \n");
            printf("IP : %s:%d: %s\n\n", inet_ntoa(retourServer.sin_addr), ntohs(retourServer.sin_port), msg);

        }

        printf("Message : ");
        gets(msg);
        printf("\n\n");

        retourWrite = write(retourAccept, &msg, sizeof(msg));
        if(retourWrite == -1)
        {
            printf("Erreur write\n");
            printf("%s", strerror(errno));
            exit(errno);
        }

    }
    close(retourAccept);
    return 0;
}
