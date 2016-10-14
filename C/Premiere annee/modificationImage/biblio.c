#include "biblio.h"
#define TAILLEMAX 255

void afficheEnTeteFichierBmp(FILE* pImage)
{
    enTeteFichierBMP enTete;
    fread(&enTete, sizeof(enTeteFichierBMP), 1, pImage);

    printf("Signature : %c%c\nTaille : %d\nRéserve : %d\nAdresse relative : %d\n",enTete.signature[0],enTete.signature[1],enTete.tailleFichier,enTete.reserve,enTete.adresseRelative);


}

void afficheEnTeteImageBmp(FILE* pImage)
{
    enTeteImageBMP enTete;
    fread(&enTete, sizeof(enTeteImageBMP), 1, pImage);
    printf("Taille en tête : %d\nLargeur : %d\nHauteur : %d\n",enTete.tailleEnTete,enTete.largeur,enTete.hauteur);
    printf("Nombre de plans : %d\nBits utilisés pp : %d\nCompression : %d\nTaille image : %d\n",enTete.nbPlan,enTete.bitParPixel,enTete.typeCompression,enTete.tailleImage);
    printf("Resolution h : %d\nResolution v : %d\nNombre couleurs : %d\nNombre couleurs importantes : %d\n",enTete.resoHorizontale,enTete.resoVerticale,enTete.nbCouleursUtilisees,enTete.nbCouleursImportantes);

}
