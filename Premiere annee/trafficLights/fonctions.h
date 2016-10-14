#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define NBCARMAX 50

#define RESET "\033[1;0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"

enum etat {RECOUVREMENT,VERT,ORANGE,ROUGE};

typedef struct {

    enum etat etatActuel;
    char id[NBCARMAX];
    char debut;
    char finCycle;
    int timer[4];
    char pinRouge;
    char pinOrange;
    char pinVert;
}feu;

int changerEtat(feu *pfeu);

int initialisation(feu *pfeu);

void effacerEcran();

#endif // FONCTIONS_H_INCLUDED
