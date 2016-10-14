#include <stdio.h>
#include <stdlib.h>
#define NBETAT 3

int main()
{
    unsigned char meteo = 0x12;
    unsigned char tendance;
    unsigned char etat;
    char *tendancePression[NBETAT]={"stable", "en hausse", "en baisse"};
    char *etatCiel[NBETAT]={"pluvieux", "nuageux", "ensoleille"};

    tendance = meteo & 0x0F;

    etat = meteo & 0xF0;
    etat = etat >> 4;

    printf("La pression est %s\n", tendancePression[tendance]);
    printf("Le ciel est %s\n", etatCiel[etat]);



    /*switch (tendance)
    {
    case 0:
        printf("Pression stable \n");
        break;
    case 1:
        printf("Pression en hausse \n");
        break;
    case 2:
        printf("Pression en baisse \n");
        break;
    }

    switch (etat)
    {
    case 0:
        printf("Ciel pluvieux\n");
        break;
    case 16:
        printf("Ciel nuageux\n");
        break;
    case 32:
        printf("Ciel ensoleille\n");
        break;
    }*/

    return 0;
}
