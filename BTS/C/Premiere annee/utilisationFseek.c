#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define TAILLEMAX 50

int main()
{
    int largeur,hauteur,nbCouleur;

    FILE *pPicture = fopen("chemin/vers/un/fichier/bmp", "r");

    if(errno != NULL){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }

    fseek(pPicture, 18, SEEK_SET);

    fread(&largeur, sizeof(int), 1, pPicture);

    fread(&hauteur, sizeof(int), 1, pPicture);

    fseek(pPicture, 28, SEEK_CUR);

    fread(&nbCouleur, sizeof(int), 1, pPicture);

    printf("%d\n",largeur);
    printf("%d\n",hauteur);
    printf("%d",nbCouleur);

    return 0;
}
