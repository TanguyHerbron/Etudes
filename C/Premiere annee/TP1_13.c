#include <stdio.h>
#include <stdlib.h>

int main()
{
    char caractere;

    printf("Donner un caractère: ");
    scanf("%s", &caractere);
    printf("La valeur décimale est %d.\n", caractere);
    printf("La valeur hexadécimale est 0x%x.\n", caractere);

}
