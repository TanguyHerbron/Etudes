#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tempMin[31];
    float tempMax[31];
    int i;
    float testTempMin;
    float testTempMax;
    int jourTempMin;
    int jourTempMax;

    for(i = 0; i <= 30; i++){
        printf("Entrer température minimale : ");
        scanf("%f", &tempMin[i]);
        printf("Entrer température maximale : ");
        scanf("%f", &tempMax[i]);
    }

    testTempMax = tempMax[1];
    testTempMin = tempMin[1];

    for(i = 0; i <= 30; i++){
        if(tempMax[i] > testTempMax){
            jourTempMax = i;
            testTempMax = tempMax[i];
        }
        if(tempMin[i] < testTempMin){
            jourTempMin = i;
            testTempMin = tempMin[i];
        }
    }

    printf("La température maximale a été relevée le %d de ce mois-ci et elle était de %.1f.\n", jourTempMax, testTempMax);
    printf("La température minimale a été relevée le %d de ce mois-ci et elle était de %.1f.", jourTempMin, testTempMin);


}
