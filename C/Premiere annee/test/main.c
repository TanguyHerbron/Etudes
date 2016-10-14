#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cote;
    float chiffre = 1, milieu = 0, compteur = 0;
    printf("Saisir un entier impaire :");
    scanf("%f", &cote);
    for(int boucleColonne = 1; boucleColonne <= cote/2 + 1; boucleColonne++){
            for(int boucleZero = 1; boucleZero < boucleColonne; boucleZero++){
                printf("0");
            }
            for(int boucleLigne = 0; boucleLigne <= cote + 1 - boucleColonne*2; boucleLigne++){
                printf("%.0f", chiffre);
                chiffre++;
            }
            for(int boucleZero = 1; boucleZero < boucleColonne; boucleZero++){
                printf("0");
            }
            printf("\n");
    }
    for(int boucleColonne = 1; boucleColonne <= cote/2; boucleColonne++){
        for(int boucleZero = ; boucleZero >= boucleColonne; boucleZero--){
            printf("0");
        }
        /*for(int boucleLigne = cote/2-1; boucleLigne >= 0; boucleLigne--){
            printf("%.0f", chiffre);
            chiffre++;
        }
        for(int boucleZero = cote/2; boucleZero >= boucleColonne; boucleZero++){
            printf("0");
        }
        printf("\n");*/
    }
}
