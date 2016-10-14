#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include <wiringPi.h>

#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#define NBCARMAX 50

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

#endif // FONCTIONS_H_INCLUDED
