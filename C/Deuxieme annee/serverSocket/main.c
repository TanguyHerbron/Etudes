#include "socketBibli.h"

int main()
{
    int socket;
    int choix;

    socket = demarrage();

    while(1)
    {
        printf("Type de donner a transmettre :\n");
        printf("1- Int\n");
        printf("2- Float\n");
        printf("3- Char\n");
        printf("Choix : ");

        scanf("%d", &choix);
        switch (choix)
        {
        case 1 :

            printf("Demarrage reussi, en attente de donnees.\n");
            dialogueInt(socket);
            break;
        case 2 :

            printf("Demarrage reussi, en attente de donnees.\n");
            dialogueFloat(socket);

            break;
        case 3 :

            printf("Demarrage reussi, en attente de donnees.\n");
            dialogueChar(socket);

            break;
        default :

            printf("Reponse non conforme.");
            break;
        }
    }

    return 0;
}
