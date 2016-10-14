#ifndef CERCLE_H_INCLUDED
#define CERCLE_H_INCLUDED
#include <math.h>

typedef struct {
    double x;
    double y;
    double rayon;
}typeCercle;

typeCercle *creerCercle(double xx, double yy, double rr);
void deplacerCercle(double nouveauX, double nouveauY, typeCercle *ptrCercle);
void changerRayonCercle(double nouveauRayon, typeCercle *ptrCercle);
void afficherCercle(typeCercle *ptrCercle);
float calculerPerimetre(typeCercle *ptrCercle);


#endif // CERCLE_H_INCLUDED
