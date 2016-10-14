/*********************************************************************
Nom du projet : cercle
Nom du fichier : cercle.c
*********************************************************************/
#include "cercle.h"
#include <stdio.h>
#include <stdlib.h>

typeCercle *creerCercle(double xx, double yy, double rr)
{
    typeCercle *c;
    c=(typeCercle *)malloc(sizeof(typeCercle));
    c->rayon=rr;
    c->x=xx;
    c->y=yy;
    return c;
}

void deplacerCercle(double nouveauX, double nouveauY, typeCercle *ptrCercle)
{
    ptrCercle->x=nouveauX;
    ptrCercle->y=nouveauY;
}

void changerRayonCercle(double nouveauRayon, typeCercle *ptrCercle)
{
    ptrCercle->rayon=nouveauRayon;
}

void afficherCercle(typeCercle *ptrCercle)
{
    printf("x : %.2f\n",ptrCercle->x);
    printf("y : %.2f\n",ptrCercle->y);
    printf("rayon : %.2f\n\n",ptrCercle->rayon);
}

float calculerPerimetre(typeCercle *ptrCercle)
{
    float perimetreCercle = 0;

    perimetreCercle = 2 * M_PI * ptrCercle->rayon;

    return perimetreCercle;
}

