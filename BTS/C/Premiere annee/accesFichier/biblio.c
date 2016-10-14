#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "biblio.h"

void testErreur(){
    if(errno != NULL){
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void exercice1Et2(){
    int i;
    int size;
    int lettre = 0;
    char car;

    FILE *pFich = fopen("/home/USERS/ELEVES/SNIR2015/fichierTexte1.txt", "r");

    testErreur();

    fseek(pFich, 0, 2);
    size = ftell(pFich);
    fseek(pFich, 0, SEEK_SET);

    for(i = 0; i < size; i++){
        car = fgetc(pFich);
        printf("%c", car);
        if('a' <= car && car <= 'z'){
            lettre++;
        }
    }

    printf("\n%d caracteres minuscules non accentués dans ce fichier.\n", lettre);
}

void exercice3(){
    typePersonne personne;
    FILE *pFich = fopen("personnes.txt", "w+");
    int i;

    testErreur();

    for(i = 0; i < NBPERSONNE; i++){
        printf("Nouvelle personne :\n");
        printf("\tNom :");
        scanf("%s", personne.nom);
        fprintf(pFich, "%s", personne.nom);
        fprintf(pFich, "\n");
        printf("\tPrenom :");
        scanf("%s", personne.prenom);
        fprintf(pFich, "%s", personne.prenom);
        fprintf(pFich, "\n");
        printf("\tAge :");
        scanf("%d", &personne.age);
        fprintf(pFich, "%d", personne.age);
        fprintf(pFich, "\n");
        printf("\tPoids :");
        scanf("%.2f", &personne.poids);
        fprintf(pFich, "%f", personne.poids);
        fprintf(pFich, "\n");
        printf("\tSexe (m ou f) :");
        scanf(" %c", &personne.sexe);
        fprintf(pFich, "%c", personne.sexe);
        fprintf(pFich, "\n");
    }
}

void exercice9(){
    FILE *pFich = fopen("/home/USERS/ELEVES/SNIR2015/adeneu/personne.txt", "r");
    typePersonne personneAxel;

    testErreur();

    fscanf(pFich, "%s", personneAxel.nom);
    fscanf(pFich, "%s", personneAxel.prenom);
    fscanf(pFich, "%d", personneAxel.age);

    printf("%s\n", personneAxel.nom);
    printf("%s\n", personneAxel.prenom);
    printf("%d",personneAxel.age);


}

void exercice3HautNiveau(){
    typePersonne personne;
    FILE *pFich = fopen("personnes.b", "w+");
    int i;

    testErreur();

    for(i = 0; i < NBPERSONNE; i++){
        printf("Nouvelle personne :\n");
        printf("\tNom :");
        scanf("%s", personne.nom);
        fwrite(personne.nom, 50, 1, pFich);
        fwrite("\n", 2, 1, pFich);
        printf("\tPrenom :");
        scanf("%s", personne.prenom);
        fwrite(personne.prenom, 50, 1, pFich);
        fwrite("\n", 2, 1, pFich);
        printf("\tAge :");
        scanf("%d", &personne.age);
        fwrite(&personne.age, 4, 1, pFich);
        fwrite("\n", 2, 1, pFich);
        printf("\tPoids :");
        scanf("%.2f", &personne.poids);
        fwrite(&personne.poids, 4, 1, pFich);
        fwrite("\n", 2, 1, pFich);
        printf("\tSexe (m ou f) :");
        scanf(" %c", &personne.sexe);
        fwrite(&personne.sexe, 4, 1, pFich);
        fwrite("\n", 2, 1, pFich);
    }

    fcloseall();
}
