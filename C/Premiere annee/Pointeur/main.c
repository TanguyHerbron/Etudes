#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptrCar;
    int *ptrEntier;
    float *ptrReel;
    char chaine[]="12345678000A";
    int i;
    ptrCar = chaine ;
    ptrEntier = (int *)chaine ;
    ptrReel = (float *)chaine ;
    for(i=0;i<3;i++)
    {
        printf("ptrCar = %X\t*ptrCar = %c\n",ptrCar,*ptrCar);
        printf("ptrEntier = %X\t*ptrEntier = %d\n",ptrEntier,*ptrEntier);
        printf("ptrReel = %X\t*ptrReel = %f\n",ptrReel,*ptrReel);

        ptrCar++;
        ptrEntier++;
        ptrReel++;
        printf("\n");
    }
}
