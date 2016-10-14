#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int valeur = 0;
    int traitement;
    unsigned long binaire = 2147483648;
    int espacement = 0;
    printf("Entrer une valeur entière :");
    scanf("%d", &valeur);
    for(traitement = 1; traitement <= 32; traitement++){
        if(valeur >= binaire){
            printf("1");
            valeur = valeur - binaire;
        }else{
            printf("0");
        }
        binaire = binaire /2;

        if(traitement % 4 == 0){
            printf(" ");
        }
    }
}
