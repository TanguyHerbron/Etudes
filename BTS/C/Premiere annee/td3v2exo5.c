#include <stdio.h>
#include <stdlib.h>

int main()
{
    int annee;
    printf("Entrer une année :");
    scanf("%d", &annee);
    if(annee%4 != 0){
        printf("L'année entrée n'est pas bissextile.\n");
    }else{
        if(annee%100 == 0 && annee%400 != 0){
            printf("L'année n'est pas bissextile.\n");
        }else{
            printf("L'annéé est bissextile.\n");
        }
    }
};
