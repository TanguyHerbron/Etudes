#include "biblio.h"

void testErreur(int retour, int valeurCorrecte, char messageErreur[])
{
    if(retour != valeurCorrecte)
    {

        printf("Erreur lors de : %s.%d\n", messageErreur, errno);
        exit(0);
    }
}

void decompressBMP(char fichierCompresse[], char fichierGenere[])
{
    int i;

    enTeteFichierBMP enTeteFichier;
    enTeteImageBMP enTeteImage;
    rle couple;
    couleur palette[NBCOULEURS];

    FILE *imageCompress = fopen(fichierCompresse, "r");
    FILE *imageGenere = fopen(fichierGenere, "w+");

    if(imageCompress == NULL){
        printf("Impossible car le premier fichier est invalide.\n");
        exit(0);
    }
    if(imageGenere == NULL){
        printf("Impossible car le second fichier est invalide.\n");
        exit(0);
    }

    testErreur(fread(&enTeteFichier, sizeof(enTeteFichier), 1, imageCompress), 1, "copie enTeteFichier");
    testErreur(fwrite(&enTeteFichier, sizeof(enTeteFichier), 1, imageGenere), 1, "ecriture enTeteFichier");
    testErreur(fread(&enTeteImage, sizeof(enTeteImage), 1, imageCompress), 1, "copie enTeteImage");
    enTeteImage.typeCompression = 0;
    testErreur(fwrite(&enTeteImage, sizeof(enTeteImage), 1, imageGenere), 1, "ecriture enTeteImage");
    testErreur(fread(palette, sizeof(couleur), NBCOULEURS, imageCompress), NBCOULEURS, "copie palette");
    testErreur(fwrite(palette, sizeof(couleur), NBCOULEURS, imageGenere), NBCOULEURS, "ecriture palette");

    while(fread(&couple, sizeof(rle), 1, imageCompress) == 1)
    {
        for(i = 0; i < couple.repetition; i++)
        {
            testErreur(fwrite(&couple.valCouleur, sizeof(char), 1, imageGenere), 1, "ecriture valCouleur");
        }
    }

    fclose(imageCompress);
    fclose(imageGenere);
}

void compresBMP(char fichierDecompresse[], char fichierGenere[])
{
        char valOctet;
    char octetSuivant;
    unsigned int ligne;
    short int compteur;
    char finLigne = 0;

    enTeteFichierBMP enTeteFichier;
    enTeteImageBMP enTeteImage;
    couleur palette[NBCOULEURS];

    FILE *imageDecompress = fopen(("%s%s", fichierDecompresse, ".bmp"), "r");
    FILE *imageGenere = fopen(fichierGenere, "w+");

    if(imageDecompress == NULL){
        printf("Impossible car le premier fichier est invalide.\n");
        exit(0);
    }
    if(imageGenere == NULL){
        printf("Impossible car le second fichier est invalide.\n");
        exit(0);
    }

    testErreur(fread(&enTeteFichier, sizeof(enTeteFichier), 1, imageDecompress), 1, "copie enTeteFichier");
    testErreur(fwrite(&enTeteFichier, sizeof(enTeteFichier), 1, imageGenere), 1, "ecriture enTeteFichier");
    testErreur(fread(&enTeteImage, sizeof(enTeteImage), 1, imageDecompress), 1, "copie enTeteImage");
    enTeteImage.typeCompression = 1;
    testErreur(fwrite(&enTeteImage, sizeof(enTeteImage), 1, imageGenere), 1, "ecriture enTeteImage");
    testErreur(fread(palette, sizeof(couleur), NBCOULEURS, imageDecompress), NBCOULEURS, "copie palette");
    testErreur(fwrite(palette, sizeof(couleur), NBCOULEURS, imageGenere), NBCOULEURS, "ecriture palette");

    testErreur(fread(&valOctet, sizeof(char), 1, imageDecompress), 1, "premier valOctet");
    compteur = 0;
    ligne = 0;

    while(fread(&octetSuivant, sizeof(char), 1, imageDecompress) == 1)
    {
        if(valOctet == octetSuivant && compteur < 255 && ligne < enTeteImage.largeur)
        {
            compteur++;
            ligne++;
        }
        else
        {
            testErreur(fwrite(&compteur, sizeof(char), 1, imageGenere), 1, "ecriture compteur");
            testErreur(fwrite(&valOctet, sizeof(char), 1, imageGenere), 1, "ecriture valOctet");

            compteur = 0;
            valOctet = octetSuivant;

            if(ligne >= enTeteImage.largeur)
            {
                testErreur(fwrite(&finLigne, sizeof(char), 1, imageGenere), 1, "ecriture retourLigne");
                testErreur(fwrite(&finLigne, sizeof(char), 1, imageGenere), 1, "ecriture retourLigne");
                ligne = 0;
            }

        }
    }

    testErreur(fwrite("0", sizeof(char), 1, imageGenere), 1, "ecriture finFichier");
    testErreur(fwrite("1", sizeof(char), 1, imageGenere), 1, "ecriture finFichier");

    fclose(imageDecompress);
    fclose(imageGenere);
}

void compressBMP(char fichierDecompresse[], char fichierGenere[])
{
    char octet;
    char ch;

    char* nomfichier = "RLE.bmp";
    strcat(fichierDecompresse, nomfichier);

    FILE *imageDecompress = fopen(fichierDecompresse, "r");
    FILE *imageGenere = fopen(fichierGenere, "w+");

    if(imageDecompress == NULL){
        printf("Impossible car le premier fichier est invalide. %s\n", fichierDecompresse);
        exit(0);
    }
    if(imageGenere == NULL){
        printf("Impossible car le second fichier est invalide.\n");
        exit(0);
    }

    while(fread(&octet, sizeof(char), 1, imageDecompress) == 1)
    {
        testErreur(fwrite(&octet, sizeof(char), 1, imageGenere), 1, "ecriture compteur");
    }

    fclose(imageDecompress);
    fclose(imageGenere);
}
