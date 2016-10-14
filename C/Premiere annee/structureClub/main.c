#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"
#define NBINSCRITMAX 5000
#define TAILLEMAX 50

int main()
{
    int choix;
    int boucle;
    char numCarteAdherent[TAILLEMAX];
    int indiceAdherent=0;

    typeAdherent *adherent[NBINSCRITMAX];// = (typeAdherent*) malloc(NBINSCRITMAX*(sizeof(typeAdherent)));

    printf("Bienvenue au club de tennis du Mans.\n\n");

    do{
        printf("Que voulez-vous faire ?\n");
        printf("1- M'inscrire\n");
        printf("2- Afficher un adhérent en particulier\n");
        printf("3- Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            adherent[indiceAdherent] = nouvelAdherent();
            indiceAdherent++;
            break;
        case 2:
            printf("\nQuel adhérent voulez-vous afficher ?");
            scanf("%s", numCarteAdherent);
            afficherUnAdherent(adherent, numCarteAdherent, indiceAdherent);
            break;
        case 3:
            printf("\nAu revoir.\n");
            break;
        default:
            printf("\nChoix inccorecte.\n");
            break;
        }
    }while(choix < 3);

    //liberation de la memoire
    for(boucle = 0; boucle < indiceAdherent; boucle++){
        free(adherent[boucle]);
    }

    return 0;
}
