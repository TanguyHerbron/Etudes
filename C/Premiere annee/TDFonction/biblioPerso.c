
#include <stdio.h>
#include <stdlib.h>

void afficherMenu(char sexe){
    if(sexe == 'f'){
        printf("Menu pour femme\n");
    }
    if(sexe == 'h'){
        printf("Menu pour homme\n");
    }
}

float additionReel(float v1, float v2){
    return v1+v2;
}

void afficherCarrer(int v1){
    printf("%d", v1*v1);
}

int calculerCarrer(int v1){
    return v1*v1;
}

float calculerDiscriminant(float a, float b, float c){
    return b*b-4*a*c;
}

void afficherRacines(float a, float b, float c){
    int delta = b*b-4*a*c;
    if(delta > 0){
        printf("Il y a deux solutions.\n");
        printf("La première est %.2f.\n", (-b+(delta/delta))/(2*a));
        printf("La seconde est %.2f.\n", (-b-(delta/delta))/(2*a));
    }
    if(delta == 0){
        printf("Il n'y a qu'une solution qui est %.2f.\n", -b/(2*a));
    }
    if(delta < 0){
        printf("Le discriminant n'admet aucune solution.\n");
    }
}

void afficherCarre(int cote){
    int boucleHor;
    int boucleVer;
    for(boucleVer = 0; boucleVer < cote; boucleVer++){
        for(boucleHor = 0; boucleHor < cote; boucleHor++){
            printf("*");
        }
        printf("\n");
    }
}
