/* Fichier d'entête cadran.h auteur : Philippe CRUCHET .... janvier 2015 */

#ifndef CADRAN_H
#define CADRAN_H

#include <ncurses.h>	// pour les fonctions d'affichage
#include <unistd.h> 	// pour sleep

/**
Classe pour l'affichage
@author Cruchet Philippe
*/

class Cadran
{
private:
    int posX;
    int posY;
    int hauteur;
    int largeur;

public:
    Cadran(const int _posX=1,const int _posY=1,const int _hauteur=2,const int _largeur=10);
    ~Cadran();
    void Afficher(const char *texte, const int position=0);
    void Afficher(const int valeur,const int position=0);

};

#endif
