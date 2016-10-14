#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10

int main()
{
    int tabEntier[TAILLE];
    int tabInver[TAILLE];
    int i;

    for(i = 0; i < TAILLE; i++){
        printf("Entrer une valeur: ");
        scanf("%d", &tabEntier[i]);
    }

    printf("Le tableau est dans l'ordre: {");

    for(i = 0; i < TAILLE; i++){
        printf("%d, ", tabEntier[i]);
    }

    printf("}");
    printf("\n");

    for(i = 0; i < TAILLE; i++){
        tabInver[9 - i] = tabEntier[i];
    }

    for(i = 0; i < TAILLE; i++){
        tabEntier[i] = tabInver[i];
    }

    printf("Le tableau est dans l'ordre inverse: {");


    for(i = 0; i < TAILLE; i++){
        printf("%d, ", tabEntier[i]);
    }

    printf("}");
}
