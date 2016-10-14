#include "fonctions.h"

int main()
{
    feu feu1;
    feu feu2;

    initialisation(&feu1);
    initialisation(&feu2);

    strcpy(feu1.id,"Voie A");
    strcpy(feu2.id,"Voie B");

    feu1.pinRouge = 1;
    feu1.pinOrange = 2;
    feu1.pinVert = 3;
    feu2.pinRouge = 4;
    feu2.pinOrange = 5;
    feu2.pinVert = 6;


    feu2.finCycle = 1;


    while(1)
    {
        effacerEcran();
        feu1.debut = feu2.finCycle;
        changerEtat(&feu1);
        feu2.debut = feu1.finCycle;
        changerEtat(&feu2);

        sleep(1);
    }
    return 0;
}
