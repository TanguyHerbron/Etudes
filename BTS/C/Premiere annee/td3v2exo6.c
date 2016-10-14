#include <stdio.h>
#include <stdlib.h>

int main()
{
    int combinaison = 164;
    int chiffre;
    int boucle = 0;
    printf("---------\n");
    printf("|Cerrure|\n");
    printf("---------\n");

    do{
        printf("Entrer une combinaison :");
        scanf("%d", &chiffre);
        if(combinaison < 999){
            printf("Valeur saisie incorrecte\n");
        }else{
            if(combinaison == chiffre){
                printf("Code validé.\n");
                boucle += 5;
            }else{
                printf("Code incorrect\n");
            }
        }
        boucle++;
    }while(boucle < 3);
    if(boucle == 3){
        printf("Le nombre d'erreurs authorisées a été dépassé.\n");
    }
}
