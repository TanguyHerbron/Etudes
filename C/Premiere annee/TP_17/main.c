#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,c,resultat;

    printf("Dans l'ordre, entrer les valeurs de a, de b et de c pour l'équation ax²+bx+c=0.\n");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    resultat = b * b - 4 * a * c;
    if(resultat > 0){
        printf("L'équation admet 2 solutnios.");
    }else if(resultat == 0){
        printf("L'équation admet une solution.");
    }else{
        printf("L'équation n'admet aucune solution.");
    }

}
