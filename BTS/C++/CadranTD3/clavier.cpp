/**************************************************************************
   Classe Clavier
   Auteur : Philippe CRUCHET - Janvier 2015
   Rôle   : Permet de gérer les touches du clavier de l'horloge.

   Projet : horloge
   IDE    : Code::Blocks sous linux utilisation de termios
 *************************************************************************/
#include <stdio.h>
#include <iostream>
#include "clavier.h"

using namespace std;

Clavier::Clavier()
/*
 *	Rôle : Initialisation du clavier
 */
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_oflag &= ~NL0;
    new_settings.c_oflag &= ~CR0;
    new_settings.c_oflag &= ~TAB0;
    new_settings.c_oflag &=~BS0;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    cfsetospeed (&new_settings, B230400);
    cfsetispeed(&new_settings, 0);
    tcsetattr(0, TCSANOW, &new_settings);
}


Clavier::~Clavier()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

char Clavier::kbhit()
/*
 *	Rôle : Lit si une touche est enfoncée
 *         Fonction non bloquante.
 *
 * Paramètre de retour 0 si aucune touche n'est enfoncée,
 *                     sinon le code de la touche.
 */
{
    char ch = 0;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0,TCSANOW, &new_settings);
    read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0,TCSANOW, &new_settings);
    return ch;
}

TOUCHES_CLAVIER Clavier::ScruterClavier()
{
    TOUCHES_CLAVIER retour;

    char key;

    key = kbhit();

    switch(key)
    {
    case '+':
        retour = PLUS;
        break;
    case '-':
        retour = MOINS;
        break;
    case 0x20:
        retour = MODE;
        break;
    case '\n':
        retour = FIN;
        break;
    default:
        retour = AUCUNE;
    }

    return retour;
}
