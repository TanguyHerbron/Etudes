#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#define NBADHERENT 5000

int main()
{
    typeAdherent **tabAdherent;
    int compteurAdherent = 0;
    int numeroCarte;
    char choix;
    printf("BASE DE DONNEE COMPLEXE SPORTIF\n\n");

    do{

        afficherMenu(compteurAdherent);
        scanf(" %c", &choix);
        switch (choix){
        case 'a':
            effacerEcran();
            tabAdherent = (typeAdherent**) realloc(tabAdherent, sizeof(typeAdherent));
            compteurAdherent = ajouterUnAdherent(tabAdherent, compteurAdherent);
            break;
        case 's':
            effacerEcran();
            printf("Numero de carte de l'adherent a supprimer :");
            scanf("%d", &numeroCarte);
            compteurAdherent = supprimerUnAdherent(tabAdherent, numeroCarte, compteurAdherent);
            break;
        case 'm':
            effacerEcran();
            printf("Numero de carte de l'adherent :");
            scanf("%d", &numeroCarte);
            modifierFiche(tabAdherent, numeroCarte, compteurAdherent);
            break;
        case 'v':
            effacerEcran();
            printf("Numero de carte de l'adherent :");
            scanf("%d", &numeroCarte);
            afficherUnAdherent(tabAdherent, numeroCarte, compteurAdherent);
            break;
        case 'l':
            effacerEcran();
            afficherAdherents(tabAdherent, compteurAdherent);
            break;
        case 'e':
            effacerEcran();
            compteurAdherent = supprimerAdherents(tabAdherent, compteurAdherent);
            break;
        case 'x':
            effacerEcran();
            sauvegardeAdherents(tabAdherent, compteurAdherent);
            break;
        case 'c':
            effacerEcran();
            compteurAdherent = chargerAdherents(tabAdherent, compteurAdherent);
            break;
        case 'q':
            break;
        default:
            printf("Saisie incorrecte.");
            break;
        }
    }while(choix != 'q');


    return 0;
}
