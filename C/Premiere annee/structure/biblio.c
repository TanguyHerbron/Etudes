#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"

typePersonne creePersonnePtr(){
    typePersonne *personne;

    personne = (typePersonne*) malloc(sizeof(typePersonne));

    printf("Quel est votre prenom ?\n");
    scanf("%s", personne->prenom);
    printf("Quel est votre nom ?\n");
    scanf("%s", personne->nom);
    printf("Quel est votre date de naissance ?\n");
    scanf("%u", &personne->annee);
    printf("Quel est votre taille ?\n");
    scanf("%f", &personne->taille);
    printf("Quel est votre poids ?\n");
    scanf("%f", &personne->poids);

    return *personne;
}

void affichePersonnePtr(typePersonne personne){
    printf("Votre nom est %s %s.\n", personne.nom, personne.prenom);
    printf("Votre année de naissance est %u.\n", personne.annee);
    printf("Votre taille est de %.2f.\n", personne.taille);
    printf("Votre poids est de %.2f.\n", personne.poids);
}
