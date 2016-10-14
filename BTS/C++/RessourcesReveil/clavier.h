/* Fichier d'entête Clavier.h auteur : Philippe CRUCHET .... janvier 2015 */

#ifndef CLAVIER_H
#define CLAVIER_H

#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
/**

*/
enum TOUCHES_CLAVIER
{

    AUCUNE,
    FIN,
    MODE,
    MOINS,
    PLUS
};

class Clavier{
    private :
	struct termios initial_settings, new_settings;

public:
    Clavier();

    ~Clavier();
    char kbhit();
    TOUCHES_CLAVIER ScruterClavier();

};

#endif
