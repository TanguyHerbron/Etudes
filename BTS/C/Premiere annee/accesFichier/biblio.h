#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#define NBMAXCAR 50
#define NBPERSONNE 1

typedef struct personne{
	char nom[NBMAXCAR];
	char prenom[NBMAXCAR];
	int age;
	float poids;
	char sexe ; // 'f' ou 'm'
}typePersonne;

void testErreur();

void exercice1Et2();

void exercice3();

void exercice9();

void exercice3HautNiveau();

#endif // BIBLIO_H_INCLUDED
