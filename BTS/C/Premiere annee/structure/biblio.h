#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#define TAILLEMAX 50

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    unsigned int annee;
    float taille;
    float poids;
}typePersonne;

typePersonne creePersonnePtr();

void affichePersonnePtr(typePersonne personne);

#endif // BIBLIO_H_INCLUDED
