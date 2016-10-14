#include <stdio.h>
#include <stdlib.h>
#include "sao.h"

int main()
{
    typePersonnage *joueur1 = NULL;
    typePersonnage *joueur2 = NULL;

    int choix;
    int i;

    do
    {
        afficherMenu(joueur1, joueur2);

        printf("Votre choix : ");

        scanf("%d", &choix);

        switch(choix)
        {
            case 1:
                if(joueur1 == NULL)
                {
                    joueur1 = creerPersonnage(joueur1);
                }
                else
                {
                    printf("Vous ne pouvez pas recréer ce personnage.\n");
                }
                break;
            case 2:
                joueur1 = chargerPersonnage();
                break;
            case 3:
                if(joueur2 == NULL)
                {
                    joueur2 = creerPersonnage(joueur2);
                }
                else
                {
                    printf("Vous ne pouvez pas recréer ce personnage.\n");
                }
                break;
            case 4:
                joueur2 = chargerPersonnage();
                break;
            case 5:
                faireUnDuel(joueur1, joueur2);
                break;
            case 6:
                for(i = 0; i < 10; i++)
                {
                    faireUnDuel(joueur1, joueur2);
                }
                break;
            case 7:
                faireUnDuel(joueur2, joueur1);
                break;
            case 8:
                for(i = 0; i < 10; i++)
                {
                    faireUnDuel(joueur2, joueur1);
                }
                break;
            case 9:
                afficherPersonnage(joueur1);
                break;
            case 10:
                afficherPersonnage(joueur2);
                break;
            case 11:
                sauvegarderPersonnages(joueur1);
                break;
            case 12:
                sauvegarderPersonnages(joueur2);
                break;
            case 13:
                printf("Au revoir.\n");
                break;
            default:
                printf("Saisie incorrecte.\n");
                break;
        }
    }
    while(choix != 13);

    return 0;
}

