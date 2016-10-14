#include "socketBibli.h"

void mort(char *cituation)
{
    printf("Erreur avec le dernier paquet recu, probleme %s : %s \n", cituation, strerror(errno));
}

int connection(struct sockaddr_in *infoServeur)
{
    char IP[16];
    int port;
    int retourSocket;

    printf("IP du serveur cible : ");
    scanf("%s", &IP);

    printf("Port du serveur cible : ");
    scanf("%d", &port);

    infoServeur->sin_addr.s_addr = inet_addr(IP);
    infoServeur->sin_family = AF_INET;
    infoServeur->sin_port = htons(port);

    retourSocket = socket(PF_INET, SOCK_DGRAM, 0);

    if(retourSocket==-1)
    {
        mort("socket");
    }

    return retourSocket;
}

void dialogueInt(int retourSocket, struct sockaddr_in *infoServeur)
{
    int msg;
    struct sockaddr_in infoServeurRetour;
    int infoServeurRetourTaille;

    while(1)
    {
        printf("Message (int) :");
        scanf("%d", &msg);

        if(sendto(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur)) == -1)
        {
            mort("sendto");
        }

        if(recvfrom(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeurRetour, &infoServeurRetourTaille) == -1)
        {
            mort("resvfrom");
        }

    }
}

void dialogueFloat(int retourSocket, struct sockaddr_in *infoServeur)
{
    float msg;
    struct sockaddr_in infoServeurRetour;
    int infoServeurRetourTaille;

    while(1)
    {
        printf("Message (float) :");
        scanf("%f", &msg);

        if(sendto(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur)) == -1)
        {
            mort("sendto");
        }

        if(recvfrom(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeurRetour, &infoServeurRetourTaille))
        {
            mort("resvfrom");
        }

    }
}

void dialogueChar(int retourSocket, struct sockaddr_in *infoServeur)
{
    char msg[LONGCHAR];
    struct sockaddr_in infoServeurRetour;
    int infoServeurRetourTaille;

    while(1)
    {
        printf("Message (float) :");
        scanf("%s", &msg);

        if(sendto(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur)) == -1)
        {
            mort("sendto");
        }

        if(recvfrom(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeurRetour, &infoServeurRetourTaille))
        {
            mort("resvfrom");
        }

    }
}
