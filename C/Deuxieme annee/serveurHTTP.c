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
    socklen_t tailleInfoServ;
    int retourSocket;
    int retourBind;
    int retourListen;
    int retourAccept;
    int retourRead;
    int retourWrite;
    char html[]=  "HTTP/1.0 200 OK\nContent-Length:68\nContent-Type: text/html\n\n<html><head><title>cc</title></head><body><h1>slt</h1></body></html>";
    char msg[512];

    infoServer.sin_family = AF_INET;
    infoServer.sin_addr.s_addr = htonl(INADDR_ANY);
    infoServer.sin_port = htons(8080);

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

    tailleInfoServ = sizeof(retourServer);
    while(1){
        retourAccept = accept(retourSocket, (struct sockaddr *)&retourServer, &tailleInfoServ);
        if(retourAccept == -1)
        {
            printf("Erreur accept\n");
            printf("%s", strerror(errno));
            exit(errno);
        }

        retourRead = read(retourAccept, &msg, sizeof(msg));
        if(retourRead == -1)
        {
            printf("Erreur read\n");
            printf("%s", strerror(errno));
            exit(errno);
        }

        printf("Nouvelle requete \n");
        printf("IP : %s:%d", retourServer.sin_addr, retourServer.sin_port);

        retourWrite = write(retourAccept, &html, sizeof(html));
        if(retourWrite == -1)
        {
            printf("Erreur write\n");
            printf("%s", strerror(errno));
            exit(errno);
        }

        close(retourAccept);
    }
    return 0;
}
