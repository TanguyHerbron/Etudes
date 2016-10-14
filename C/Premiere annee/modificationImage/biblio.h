#ifndef BIBLIO_H_INCLUDED

#define BIBLIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#pragma pack(push, 1)

typedef struct
{
    unsigned char signature[2];
    unsigned int tailleFichier;
    unsigned int reserve;
    unsigned int adresseRelative;

}enTeteFichierBMP;

typedef struct
{
    unsigned int tailleEnTete;
    unsigned int largeur;
    unsigned int hauteur;
    unsigned short nbPlan;
    unsigned short bitParPixel;
    unsigned int typeCompression;
    unsigned int tailleImage;
    unsigned int resoHorizontale;
    unsigned int resoVerticale;
    unsigned int nbCouleursUtilisees;
    unsigned int nbCouleursImportantes;

}enTeteImageBMP;

typedef struct
{
    unsigned char bleu;
    unsigned char vert;
    unsigned char rouge;
    unsigned char alpha;
}couleur;


void afficheEnTeteFichierBmp(FILE* pImage);

void afficheEnTeteImageBmp(FILE* pImage);



#endif // BIBLIO_H_INCLUDED
