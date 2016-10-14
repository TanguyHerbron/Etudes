/***************************************************************************
caveHunter.h
 ***************************************************************************/
#ifndef TRESOR_H
#define TRESOR_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define LARGEUR 20
#define HAUTEUR 10

#define TRESOR 4
#define SORTIE 5
#define PIEGE 2
#define MONSTRE 1
#define POTION 3
#define VIE 4

void initMonde( char tab[LARGEUR][HAUTEUR], int nbMonstre, int nbPotion, int nbPiege );
unsigned int aleatoire(unsigned int maxAlea);
void initPiege( char tab[LARGEUR][HAUTEUR], int nbPiege );
void initMonstre( char tab[LARGEUR][HAUTEUR], int nbMonstre );
void initPotion( char tab[LARGEUR][HAUTEUR], int nbPotion );
void afficheMonde( char tab[LARGEUR][HAUTEUR] , int posX, int posY );
unsigned int getXTresor(char tab[LARGEUR][HAUTEUR]);
unsigned int getYTresor(char tab[LARGEUR][HAUTEUR]);
unsigned int getXSortie(char tab[LARGEUR][HAUTEUR]);
unsigned int getYSortie(char tab[LARGEUR][HAUTEUR]);
void afficheTresor();
void afficheMonstre();
void affichePotion();
void affichePiege();
void afficheSortie();
void affichePerdu();
float getDistance(unsigned int xt,unsigned int yt,unsigned int xp,unsigned int yp);

#endif
