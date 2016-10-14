#include "socketBibli.h"

int main()
{
    struct sockaddr_in *infoServeur;
    int retourSocket;
    int choix;

    retourSocket = connection(&infoServeur);

    while(1)
    {
        printf("Donnee transferes par le serveur : \n");
        printf("1- Int\n");
        printf("2- Float\n");
        printf("3- Char\n");
        printf("Choix :");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            dialogueInt(retourSocket, &infoServeur);
            break;
        case 2:
            dialogueFloat(retourSocket, &infoServeur);
            break;
        case 3:
            dialogueChar(retourSocket, &infoServeur);
            break;
        default:
            printf("Mauvais choix");
            exit(0);
        }
    }

    return 0;
}
