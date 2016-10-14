#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

int main()
{
    int tab[TAILLE] = {5,7,2,1,4};
    int compare = 10000000;
    int temp;
    int tempBoucle;
    int i, j, a, caz;

    for(i = 0; i < TAILLE; i++){
        for(j = 0; j+i < TAILLE; j++){
            if(compare > tab[j+i]){
                compare = tab[j+i];
                caz = j+i;
            }
        }
        temp = tab[i];
        tab[i] = compare;
        tab[caz] = temp;
        compare = 10000000000;

    }

    for(a = 0; a < TAILLE; a++){
        printf("%d,", tab[a]);
    }
}
