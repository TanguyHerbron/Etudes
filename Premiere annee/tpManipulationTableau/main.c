#include <stdio.h>
#include <stdlib.h>
#define NB_RELEVE 5

int main()
{
    int testUnsigned;
    int boucle;
    float moyenne = 0;
    unsigned int valMin, valMax;
    unsigned int nuagePoints[NB_RELEVE];

    for(boucle = 0; boucle < NB_RELEVE; boucle++)
    {
        do{
            printf("Valeur à entrer :");
            scanf("%d", &testUnsigned);
        }while(testUnsigned < 0 || testUnsigned > 4096);
        nuagePoints[boucle] = testUnsigned;
    }

    // Determination du min et du max
    valMin = nuagePoints[0];
    valMax = nuagePoints[0];
    for(boucle = 0; boucle < NB_RELEVE; boucle++)
    {
        if(nuagePoints[boucle] > valMax)
        {
            valMax = nuagePoints[boucle];
        }
        if(nuagePoints[boucle] < valMin)
        {
            valMin = nuagePoints[boucle];
        }
    }
    // Calcul de la moyenne
    for(boucle = 0; boucle < NB_RELEVE; boucle++)
    {
        moyenne = moyenne + nuagePoints[boucle];
    }
    moyenne = moyenne - (valMax + valMin);
    moyenne = moyenne / (NB_RELEVE - 2);

    printf("Moyenne :%.2f\n", moyenne);
    return 0;
}
