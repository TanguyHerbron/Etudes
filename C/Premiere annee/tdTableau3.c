#include <stdio.h>
#include <stdlib.h>
#define TAILLEMAX 255

int main()
{
    float tabVal[TAILLEMAX];
    int nbVal = 10;
    int i;
    float tabValNeg[nbVal];
    float tabValPos[nbVal];
    float sommeTabValNeg = 0;
    float miniPos;
    float maxiPos;

    for(i = 0; i < nbVal; i++){
        printf("Entrer une valeur : ");
        scanf("%f", &tabVal[i]);

        if(tabVal[i] < 0){
            tabValNeg[i] = tabVal[i];
            sommeTabValNeg = sommeTabValNeg + tabVal[i];
        }

        if(tabVal[i] > 0){
            tabValPos[i] = tabVal[i];
        }
    }

    miniPos = tabVal[1];
    maxiPos = tabVal[1];

    for(i = 0; i < nbVal; i++){
        if(miniPos > tabVal[i]){
            miniPos = tabVal[i];
        }

        if(maxiPos < tabVal[i]){
            maxiPos = tabVal[i];
        }
    }

    printf("La somme des valeurs négatives est égal à %.0f.\n", sommeTabValNeg);
    printf("Il y a %d valeurs nulles dans tabVal.\n", TAILLEMAX - nbVal);
    printf("La plus grosse valeur de tabValPos est %.0f.\n", maxiPos);
    printf("La plus petite valeur de tabValPos est %.0f.\n", miniPos);

}
