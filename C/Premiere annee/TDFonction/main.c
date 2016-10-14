#include <stdio.h>
#include <stdlib.h>
#include "biblioPerso.h"

int main()
{
    char sexe;
    int valeurCarrer;
    int coteCarre;
    int coteRectLargeur;
    int coteRectLongueur;
    float valeurAddition1;
    float valeurAddition2;
    float a;
    float b;
    float c;

    printf("Bonjour.\n");
    printf("Votre sexe :");
    scanf("%c", &sexe);

    afficherMenu(sexe);

    printf("\nSaisissez une valeur :");
    scanf("%f", &valeurAddition1);
    printf("Saisissez une seconde valeur :");
    scanf("%f", &valeurAddition2);
    printf("Votre somme est égale à %.2f.\n", additionReel(valeurAddition1, valeurAddition2));

    printf("\nSaisissez une valeur pour afficher un carré :");
    scanf("%d", &valeurCarrer);
    afficherCarrer(valeurCarrer);

    printf("\n\nSaisissez une valeur pour calculer un carré :");
    scanf("%d", &valeurCarrer);
    printf("Votre valeur calculée au carré donne %d.", calculerCarrer(valeurCarrer));

    printf("\n\nNous voulons calculer un discriminant.\n");
    printf("Saisissez a :");
    scanf("%f", &a);
    printf("Saisissez b :");
    scanf("%f", &b);
    printf("Saisissez c :");
    scanf("%f", &c);
    printf("Votre discriminant est %.2f.\n", calculerDiscriminant(a, b, c));
    afficherRacines(a, b, c);

    printf("\nNous voulons dessiner un carré.\n");
    printf("Saisissez la taille du côté :");
    scanf("%d", &cote);
    afficherCarre(cote);

    printf("\nNous voulons dessiner un carré.\n");
    printf("Saisissez la taille du côté :");
    scanf("%d", &cote);
    afficherCarre(cote);

    return 0;
}
