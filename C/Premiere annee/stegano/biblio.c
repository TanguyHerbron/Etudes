#include "biblio.h"

void afficherSteganoTxt(char nomFichier[], int pas)
{
    char phraseMystere[TAILLEMAX];
    int i = 0;

    FILE *imageTxtCache = fopen(nomFichier, "r+");

    if(imageTxtCache == NULL){
        printf("Impossible car le premier fichier est invalide.\n");
        exit(0);
    }

    fseek(imageTxtCache, 1078, SEEK_SET);

    while(fread(&phraseMystere[i], sizeof(char), 1, imageTxtCache) == 1)
    {
        i += pas;
    }

    printf("%s", phraseMystere);
}
