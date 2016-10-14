#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nbValeur;
    int tabValeur[255];
    int loop;
    int plusGrosseValeur;

    printf("Combien de valeur avez-vous à comparer ?\n");
    scanf("%d", &nbValeur);
    printf("\n");

    for(loop = 1; nbValeur >= loop; loop++){
        printf("%d valeur: ", loop);
        scanf("%d", &tabValeur[loop]);
        if(plusGrosseValeur <= tabValeur[loop]){
            plusGrosseValeur = tabValeur[loop];
        }
    }
    printf("\nLa plus grosse valeur est %d.\n",plusGrosseValeur);

}
