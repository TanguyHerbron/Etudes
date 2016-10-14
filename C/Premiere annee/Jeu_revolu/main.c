#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int aTrouver = rand() % 100;
    int trouve = 0;
    int userEnter, essai = 0;
    while(trouve == 0){
    printf("Entrer une valeur :");
    scanf("%d", &userEnter);
        if(userEnter < aTrouver){
            printf("La valeur à trouver est plus grande.\n");
            essai++;
        }else{
            if(userEnter > aTrouver){
                printf("La valeur à trouver est plus petite.\n");
                essai++;
            }else{
                printf("Vous avez trouvé en %d essai(s).", essai);
                trouve = 1;
            }
        }
    }
}
