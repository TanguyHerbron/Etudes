#include <stdio.h>
#include <stdlib.h>

int main()
{
    float reel;
    printf("Saisir une valeur réelle: ");
    scanf("%f", &reel);

    if(3.14 >= reel && reel <3.16 )
    {
        printf("Ok");
    }

    int entier;
    printf("Saisir une valeur entière: ");
    scanf("%d", &entier);

    if(0 <= entier && entier <= 20)
    {
        printf("Note ok");
    }

    char caractere;
    printf("Saisir un caractère: ");
    scanf("%c", &caractere);
    if('a' <= caractere && caractere <= 'z')
    {
        printf("C'est une lettre.");
    }
    else
    {
        printf("Ce n'est pas une lettre.");
    }

    char caractere;
    printf("Saisir un caractère: ");
    scanf("%c", &caractere);
    if(('a' <= caractere && caractere <= 'z') || ('A' <= caractere && caractere <= 'Z'))
    {
        printf("C'est une lettre.");
    }
    else
    {
        printf("Ce n'est pas une lettre.");
    }
}

