#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

int main()
{
    int choixExercice;

    printf("Quel exercice voulez-vous essayer ?\n");
    printf("1- Adresse des mois\n");
    printf("2- Enlever le caractere e\n");
    printf("3- Nom et chaine de caractere\n");
    printf("4- Inversion de float\n");
    printf("5- Discriminant\n");
    printf("Votre choix : ");

    scanf("%d", &choixExercice);

    switch (choixExercice){
    case 1:
        exercice1();
        break;
    case 2:
        exercice2();
        break;
    case 3:
        exercice3();
        break;
    case 4:
        exercice4();
        break;
    case 5:
        exercice5();
        break;
    default:
        break;
    }


    return 0;
}
