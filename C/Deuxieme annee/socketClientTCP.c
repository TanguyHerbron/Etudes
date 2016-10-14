#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

typedef struct{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[10];
}datePerso;

int main()
{
    datePerso perso;
    datePerso retourPerso;
    struct sockaddr_in infoServeur;
    struct sockaddr_in infoServeurRetour;
    int infoServeurRetourTaille;
    int retourSocket;
    int retourConnect;
    int retourRead;
    int retourWrite;
    int socketFd;
    int retourMsg;

    int msg = 8;

    perso.jour = 17;
    perso.mois = 12;
    perso.annee = 1997;
    strcpy(perso.jourDeLaSemaine, "Lundi");

    infoServeur.sin_addr.s_addr = inet_addr("172.18.58.142");
    infoServeur.sin_family = AF_INET;
    infoServeur.sin_port = htons(5555);

    retourSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(retourSocket == -1)
    {
        printf("Erreur socket\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourConnect = connect(retourSocket, &infoServeur, sizeof(infoServeur));
    if(retourSocket == -1)
    {
        printf("Erreur connect\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourWrite = write(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur));
    if(retourSocket == -1)
    {
        printf("Erreur write\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    retourRead = read(retourSocket, &retourMsg, sizeof(retourMsg), 0, (struct sockaddr *)&infoServeurRetour, &infoServeurRetourTaille);
    if(retourSocket == -1)
    {
        printf("Erreur read\n");
        printf("%s", strerror(errno));
        exit(errno);
    }

    printf("%d", retourMsg);

    close(retourSocket);

    return 0;
}
