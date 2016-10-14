#include <stdio.h>
#include <stdlib.h>

int main()
{
    int note[24];
    int bouclage;
    for(bouclage = 0; bouclage < 24; bouclage++){
        printf("Entrer une note : ");
        scanf("%d", &note[bouclage]);
    }

    printf("\n");

    for(bouclage = 0; bouclage < 24; bouclage++){
        printf("L'élève %d a eu %d.\n", bouclage+1, note[bouclage]);
    }
}
