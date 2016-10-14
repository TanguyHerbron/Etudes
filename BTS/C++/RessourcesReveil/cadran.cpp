/***************************************************************************
   Classe Cadran
   Auteur : Philippe CRUCHET - Janvier 2015
   Rôle   : Permet de définir un cadran digital, la taille est définie par
            le constructeur.

   Projet : horloge
   IDE    : Code::Blocks sous linux avec utilisation de la librairie ncurses
 ***************************************************************************/
#include <stdio.h>
#include "cadran.h"// a faire


Cadran::Cadran(const int _posX,const int _posY,const int _hauteur,const int _largeur)
 : posX(_posX), posY(_posY), hauteur(_hauteur), largeur (_largeur)
/*
 *	Rôle : Initialisation du cadran
 *	Paramètres : _posX,_posY position du coin gauche du cadran
 *                   _hauteur, _largeur dimensions du cadran
 */
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();// a faire
	mvaddch(posY, posX, '+');
	mvaddch(posY, posX +  largeur, '+');
	mvaddch(posY + hauteur, posX, '+');
	mvaddch(posY + hauteur, posX + largeur, '+');
	mvhline(posY, posX + 1, '-', largeur - 1);
	mvhline(posY + hauteur, posX + 1, '-', largeur - 1);
	mvvline(posY + 1, posX, '|', hauteur - 1);
	mvvline(posY + 1, posX + largeur, '|', hauteur - 1);
}


Cadran::~Cadran()
{
	endwin();
}

void Cadran::Afficher(const char *texte, const int position)
{
	mvprintw(posY + 1 , posX + 1 + position, texte ) ;
	mvprintw(0,0,"") ;
	refresh() ;
}

void Cadran::Afficher(const int valeur,const int position)
{
	char *texte = new char[largeur+1] ;
	if(texte != NULL)
	{
		sprintf(texte,"%02d",valeur);
		Afficher(texte,position) ;
		delete texte ;
	}

}
