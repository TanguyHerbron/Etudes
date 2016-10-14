#include <stdio.h>
#include <stdlib.h>
#define length 255

int main()
{

    char chaineScan [length];
    char chaineGet [length];


    printf("Entrer chaine de caractère, test pour gets: ");
    fgets(chaineGet, sizeof(chaineGet), stdin);
    printf("La saisie retenue est: %s\n", chaineGet);

    printf("Entrer chaine de caractère, test pour scanf: ");
    scanf("%s", chaineScan);
    printf("La saisie retenue est: %s\n", chaineScan);
}
