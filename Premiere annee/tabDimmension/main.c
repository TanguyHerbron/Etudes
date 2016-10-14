#include <stdio.h>
#include <stdlib.h>
#define NBCOL 5
#define NBLIGNE 3

int main()
{
    int tab[NBCOL][NBLIGNE];
    int boucleLigne, boucleColonne, modification = 0;
    for(boucleLigne = 0; boucleLigne < NBLIGNE; boucleLigne++){
        for(boucleColonne = 0; boucleColonne < NBCOL; boucleColonne++){
            tab[boucleColonne][boucleLigne] = modification;
            modification++;
        }
    }
    for(boucleLigne = 0; boucleLigne < NBLIGNE; boucleLigne++){
        for(boucleColonne = 0; boucleColonne < NBCOL; boucleColonne++){
            printf("%d", tab[boucleColonne][boucleLigne]);
        }
        printf("\n");
    }
    return 0;
}
