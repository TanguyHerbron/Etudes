#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 0;
    int boolean = 0;
    int varPositive = 0;
    int somme = 0;
    while(boolean == 0){
        printf("Entrer une valeur :");
        scanf("%d", &var);
        if(var < 0){
            printf("Vous avez entré une valeure néfative.\n");
            boolean++;
        }else{
            printf("Valeur correcte.\n");
            somme = somme + var;
            varPositive++;
        }
    }
    printf("Vous avez saisi %d valeurs positives et leur somme est de %d et la moyenne est de %f.\n",
           varPositive, somme, somme/varPositive);
}
