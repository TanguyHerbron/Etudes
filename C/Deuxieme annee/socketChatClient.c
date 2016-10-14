#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define LEN 512

int main()
{
    struct sockaddr_in infoServeur;
    struct sockaddr_in infoServeurRetour;
    char msg[LEN];
    int infoServeurRetourTaille;
    int retourSocket;
    int retourConnect;
    int retourRead;
    int retourWrite;
    int socketFd;

    infoServeur.sin_addr.s_addr = inet_addr("172.18.58.93");
    infoServeur.sin_family = AF_INET;
    infoServeur.sin_port = htons(3434);

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

    while (1)
    {
        printf("Message :");
        gets(msg);

        retourWrite = write(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeur, sizeof(infoServeur));
        if(retourSocket == -1)
        {
            printf("Erreur write\n");
            printf("%s", strerror(errno));
            exit(errno);
        }

        //if(select())
        //{
            retourRead = read(retourSocket, &msg, sizeof(msg), 0, (struct sockaddr *)&infoServeurRetour, sizeof(infoServeurRetour));
            if(retourRead == -1)
            {
                printf("Erreur read\n");
                printf("%s", strerror(errno));
                exit(errno);
            }

            printf("Message de %s:%d\n", inet_ntoa(infoServeur.sin_addr), ntohs(infoServeur.sin_port));
            printf("%s\n", msg);

        //}


    }

    close(retourSocket);

    return 0;
}
