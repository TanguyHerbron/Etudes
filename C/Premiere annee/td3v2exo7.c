#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int limiteA = 1;
    int limiteB = 5;
    float x = limiteA;
    double epsilon = 0.00001;
    int boucle;
    double integrale = 0;
    do{
        integrale += ((x*x + 3*x - 5) * epsilon);
        x += epsilon;
    }while(x < limiteB);
    printf("L'intégrale est égale à %f.", integrale);
}
