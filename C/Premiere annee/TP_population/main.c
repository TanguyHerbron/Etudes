#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float taillePopulation1, taillePopulation2, annee=0;
    float tauxPopulation1, tauxPopulation2;
    printf("Entrer la taille de la population 1 :");
    scanf("%f", &taillePopulation1);
    printf("Entrer la taille de la population 2 :");
    scanf("%f", &taillePopulation2);
    printf("Entrer le taux de croissance de la population 1 par an en pourcent:");
    scanf("%f", &tauxPopulation1);
    printf("Entrer le taux de croissance de la population 2 par an en pourcent:");
    scanf("%f", &tauxPopulation2);
    while(taillePopulation2 <= taillePopulation1){
        annee++;
        taillePopulation1 = taillePopulation1 * (tauxPopulation1/100+1);
        taillePopulation2 = taillePopulation2 * (tauxPopulation2/100+1);
    }
    printf("La population 2 aura dépassé la population 1 au bout de %.0f année(s).", annee);

    return 0;
}
