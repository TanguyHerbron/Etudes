#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#define NBCOULEURS 256

int main(int argc, char *argv[])
{
    enTeteFichierBMP enTeteFichier;
    enTeteImageBMP enTeteImage;
    couleur palette[NBCOULEURS];
    int i, retour;
    char pixel;

    FILE *pImage = fopen(argv[1], "r");

    FILE *pImageModif = fopen(argv[2], "w+");

    if(pImage == NULL){
        printf("Impossible car le premier fichier est invalide.\n");
        exit(0);
    }
    if(pImageModif == NULL){
        printf("Impossible car le second fichier est invalide.\n");
        exit(0);
    }

    afficheEnTeteFichierBmp(pImage);
    printf("\n\n");
    afficheEnTeteImageBmp(pImage);

    rewind(pImage);
    retour = fread(&enTeteFichier, sizeof(enTeteFichier), 1, pImage);
    retour = fwrite(&enTeteFichier, sizeof(enTeteFichier), 1, pImageModif);
    retour = fread(&enTeteImage, sizeof(enTeteImage), 1, pImage);
    retour = fwrite(&enTeteImage, sizeof(enTeteImage), 1, pImageModif);

    retour = fread(palette, sizeof(couleur), NBCOULEURS, pImage);

    for(i = 0; i < NBCOULEURS; i++)
    {
        palette[i].bleu = 0;
        palette[i].vert = 0;
    }

    retour = fwrite(palette, sizeof(couleur), NBCOULEURS, pImageModif);

    //Copie des donnees de l'image
    while(!feof(pImage))
    {
        retour = fread(&pixel, sizeof(char), 1, pImage);
        retour = fwrite(&pixel, sizeof(char), 1, pImageModif);
    };

    retour = fclose(pImage);
    retour = fclose(pImageModif);

    return 0;
}
