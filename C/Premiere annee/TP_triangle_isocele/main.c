#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cote, loopColonne, loopLigne;
    printf("Le côté du triangle est de :");
    scanf("%d", &cote);
    for(loopColonne=0; loopColonne < cote; loopColonne++){
        for(loopLigne=1; loopLigne <= cote-loopColonne; loopLigne++){
            printf("#");
        }
    printf("\n");
    }
}
