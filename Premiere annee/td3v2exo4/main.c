#include <stdio.h>
#include <stdlib.h>

int main()
{
    double hauteurEiffel = 320.755; //En m
    double epaisseurPapier = 0.076474; //En mm
    int compteur = 0;

    hauteurEiffel = hauteurEiffel * 1000; //Conversion de mm à m
    while(epaisseurPapier < hauteurEiffel){
        epaisseurPapier = epaisseurPapier*2;
        compteur++;
    }
    printf("Le papier atteindra l'épaisseur de la tour Eiffel en %d pliages.", compteur);
}
