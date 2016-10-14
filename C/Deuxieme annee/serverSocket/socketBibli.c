#include "socketBibli.h"

void mort(char *cituation)
{
    printf("Erreur avec le dernier paquet recu, probleme %s : %s \n", cituation, strerror(errno));
}

int demarrage()
{
    struct sockaddr_in infoServer;
    int retourSocket;
    int port;

    printf("Port sur lequel vous voulez lancer le serveur :");
    scanf("%d", &port);

    infoServer.sin_family = AF_INET;
    infoServer.sin_addr.s_addr = htonl(INADDR_ANY);
    infoServer.sin_port = htons(port);

    retourSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(retourSocket == -1)
    {
        mort("demarrage socket");
    }

    if(bind(retourSocket, (struct sockaddr *)&infoServer, sizeof(infoServer)) == -1)
    {
        mort("bind");
    }

    return retourSocket;

}

void dialogueInt(int socket)
{
    struct sockaddr_in infoClient;
    int infoClientTaille;
    int retourMsg;
    int retourSendTo;

    while(1)
    {
        if(recvfrom(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, &infoClientTaille) == -1)
        {
            mort("recvfrom");
            exit(errno);
        }

        printf("%d\n", retourMsg);

        if(sendto(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, sizeof(infoClient))==-1)
        {
            mort("sendto");
            exit(errno);
        }

    }

}

void dialogueFloat(int socket)
{
    struct sockaddr_in infoClient;
    int infoClientTaille;
    float retourMsg;

    while(1)
    {
        if(recvfrom(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, &infoClientTaille) == -1)
        {
            mort("recvfrom");
            exit(errno);
        }

        printf("%f\n", retourMsg);

        if(sendto(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, sizeof(infoClient))==-1)
        {
            mort("sendto");
            exit(errno);
        }

    }
}

void dialogueChar(int socket)
{
    struct sockaddr_in infoClient;
    int infoClientTaille;
    char retourMsg[CHARLEN];
    int retourSendTo;

    while(1)
    {
        if(recvfrom(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, &infoClientTaille) == -1)
        {
            mort("recvfrom");
        }

        printf("%s\n", retourMsg);

        if(sendto(socket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoClient, sizeof(infoClient))==-1)
        {
            mort("sendto");
        }

    }
}
