#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var, loop;
    printf("Le chiffre que vous voulez mutliplier est :");
    scanf("%d", &var);
    for(loop = 0; loop <= 10; loop++){
        printf("%d x %d = %d\n", loop, var, loop*var);
    }
}
