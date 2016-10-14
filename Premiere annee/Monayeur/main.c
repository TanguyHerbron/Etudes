#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque_perso.h"

int main()
{
    double valPiece[8] = {20, 10, 5, 2, 1, 0.5, 0.2, 0.1};
    double prixBoisson;
    double valeurARendre;
    int nbPiece[8] = {0, 0, 0, 5, 5, 8, 9, 12};
    int pieceUser[8] = {0, 0, 0, 0, 0};
    int pieceRendu[8] = {0, 0, 0, 0, 0};
    int choix;
    int boucle;

    printf("Bonjour.\n");

    do{
        printf("Que voulez-vous faire ?\n");
        printf("1 - Commander une boisson\n");
        printf("2 - Quitter\n");
        printf("Votre choix :");
        scanf("%d", &choix);

        switch (choix){
        case 1:
            prixBoisson = demanderBoisson();
            valeurARendre = attendrePiece(prixBoisson, pieceUser);
            printf("Somme à rendre : %.1f\n", valeurARendre);
// ajouter les pieces de l'usager dans le monnayeur
            for(boucle = 0; boucle < 8; boucle++){
                nbPiece[boucle] = nbPiece[boucle] + pieceUser[boucle];
            }

            valeurARendre = rendrePiece(valeurARendre, valPiece, nbPiece, pieceRendu);

            printf("Pieces rendues :\n");
            for(boucle = 0; boucle < 8; boucle++){
                printf("%d piece de %.1f€\n", pieceRendu[boucle], valPiece[boucle]);
            }
            break;
        case 2:
            printf("Au revoir\n");
            break;
        default:
            printf("Saisie incorrecte\n");
            break;
        }

    }while(choix != 2);


    return 0;
}
