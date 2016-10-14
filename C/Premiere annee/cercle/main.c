#include <stdio.h>
#include <stdlib.h>
#include "cercle.h"

int main()
{
    typeCercle *c1;
    typeCercle *c2;
    c1=creerCercle(3,5,10); // un cercle en (3,5) rayon 10
    c2=creerCercle(-2,4,3); // un cercle en (-2,4) rayon 3
    afficherCercle(c1);
    printf("Le périmètre de C1 = %f\n", calculerPerimetre(c1));
    afficherCercle(c2);
    printf("Le périmètre de C2 = %f\n", calculerPerimetre(c2));
    deplacerCercle(1,2,c1); // le cercle c1 est a present en (1,2)
    afficherCercle(c1);
    printf("Le périmètre de C1 = %f\n", calculerPerimetre(c1));
    changerRayonCercle(6,c2);   // le cercle c2 a un nouveau rayon de 6
    afficherCercle(c2);
    printf("Le périmètre de C2 = %f\n", calculerPerimetre(c2));

    return 0;
}
