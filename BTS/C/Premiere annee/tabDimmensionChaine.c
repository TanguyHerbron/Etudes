#include <stdio.h>
#include <stdlib.h>
#define NBMOTS 3
#define LONGMAXMOT 10

int main()
{
    char tabChaine[NBMOTS][LONGMAXMOT]={"coucou", "salut", "hello"};
    int nroMot;
    for(nroMot = 0; nroMot < NBMOTS; nroMot++){
        printf("%s", tabChaine[nroMot]);
        printf("\n");
    }
    return 0;
}
