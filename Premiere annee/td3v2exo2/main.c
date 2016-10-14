#include <stdio.h>
#include <stdlib.h>

int main()
{
    int coucou;
    printf("Dans la forêt lointaine, on entend le coucou.\n");
    printf("Combien de fois entend-on le coucou dans la forêt lointaine ?");
    for(scanf("%d", &coucou); coucou > 0; coucou--){
        printf("Coucou !\n");
    }
    printf("Fait le coucou.\n");
}
