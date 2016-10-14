#ifndef TABLEBARRES_H_INCLUDED
#define TABLEBARRES_H_INCLUDED

#include "Barre.h"

class TableBarres
{
public:
    TableBarres(short _taille);
    ~TableBarres();
    void add(Barre *pBarre);
    void AfficherCatalogue();

protected:
    short taille ;
    short index;
// No description
    Barre ** table ;
};

#endif // TABLEBARRES_H_INCLUDED
