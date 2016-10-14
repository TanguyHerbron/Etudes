#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base, fin, var;
    printf("Le début de la multiplication se fait à :");
    scanf("%d", &base);
    printf("La fin de la multiplication se fait à :");
    scanf("%d", &fin);
    printf("Le chiffre à mutliplier est :");
    scanf("%d", &var);
    while(base <= fin){
        printf("%d x %d = %d\n", base, var, base*var);
        base++;
    }
}
