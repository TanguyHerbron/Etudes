#include <stdio.h>
#include <stdlib.h>
#define DELTA 0.001

double demanderBoisson()
{
    int choixBoisson;
    double prixBoisson;

    printf("Choisissez votre boisson :\n");
    printf("1 - Café long [1.5€]\n");
    printf("2 - Café cours [0.8€]\n");
    printf("Votre choix :");
    scanf("%d", &choixBoisson);
    switch (choixBoisson){
    case 1:
        prixBoisson = 1.5;
        break;
    case 2:
        prixBoisson = 0.8;
        break;
    }
    return prixBoisson;
}

double attendrePiece(double prixBoisson, int pieceUser[])
{
    int piece;
    double somme = 0;

    do{
        printf("Le prix est de %.1f€\n", prixBoisson);
        printf("Monnaie :\n");
        printf("1 - 20€\n");
        printf("2 - 10€\n");
        printf("3 - 5€\n");
        printf("4 - 2€\n");
        printf("5 - 1€\n");
        printf("6 - 0.5€\n");
        printf("7 - 0.2€\n");
        printf("8 - 0.1€\n");
        printf("Piece a entrer :");
        scanf("%d", &piece);
        switch (piece){
        case 1:
            somme = somme + 20;
            pieceUser[0]++;
            break;
        case 2:
            somme = somme + 10;
            pieceUser[1]++;
            break;
        case 3:
            somme = somme + 5;
            pieceUser[2]++;
            break;
        case 4:
            somme = somme + 2;
            pieceUser[3]++;
            break;
        case 5:
            somme = somme + 1;
            pieceUser[4]++;
            break;
        case 6:
            somme = somme + 0.5;
            pieceUser[5]++;
            break;
        case 7:
            somme = somme + 0.2;
            pieceUser[6]++;
            break;
        case 8:
            somme = somme + 0.1;
            pieceUser[7]++;
            break;
        }
        printf("La somme que vous avez entree est de %.1f€\n", somme);
    }while(prixBoisson > somme);
    return somme - prixBoisson;
}

double rendrePiece(double rendrePrix, double valPiece[], int nbPiece[], int pieceRendu[])
{
    int boucle;
// mise à jours des pieces a rendre
    for(boucle = 0; boucle < 8; boucle++){
        // je peux rendre des pieces de la valeur courante
        if(valPiece[boucle] <= rendrePrix){
            // tant que je peux rendre des pieces de la valeur courante, je le fais
            while((rendrePrix > (valPiece[boucle]-DELTA)) && (nbPiece[boucle] != 0)){
                rendrePrix = rendrePrix - valPiece[boucle];
                pieceRendu[boucle]++;
                nbPiece[boucle]--;
            }
        }
    }

    return rendrePrix;
}
