#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long caseEchec, grain = 1, totGrain = 0;
    printf("Lorsque l'inventeur du jeu d'échec présenta son invention au roi des Perses, celui-ci fut émerveillé et informa le créateur qu'il était prêt à satisfaire n'importe quelle demande venant de sa part.\n");
    printf("Après un court instant de réflexion, l'inventeur demande qu'on lui mette 1 grain de blé dans la première case, 2 dans la deuxième, 4 dans la troisième et ainsi de suite en doublant à chaque fois le nombre de grain.\n");
    printf("Bien que surpris par la modestie de la demande, le roi ordonna à son garde grenier de préparer le présent.\n");
    for(caseEchec = 1; caseEchec <= 64; caseEchec++){
        printf("Le garde posa %lu grains dans la %lu case.\n", grain, caseEchec);
        totGrain = totGrain + grain;
        grain *= 2;
    }
    printf("Le garde grenier posa au total %lu grains, étant devenu fou, il se suicida.", totGrain);
}
