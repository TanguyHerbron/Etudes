#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main(int argc, char *argv[])
{
    int choix;

    printf("Quel exercice voulez-vous essayer ?\n");
    printf("1 - Print fichierTexte.txt et contage caracteres\n");
    printf("2 - Création d'adherents bas niveau\n");
    printf("3 - Création d'adherents haut niveau\n");
    printf("4 - Lecture txt voisin\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch(choix){
    case 1:
        exercice1Et2();
        break;
    case 2:
        exercice3();
        break;
    case 3:
        exercice3HautNiveau();
        break;
    case 4:
        exercice9();
        break;
    }

    return 0;
}
