#ifndef BARRECARREE_H_INCLUDED
#define BARRECARREE_H_INCLUDED

#include "Barre.h"

class BarreCarree : public Barre
{
private:
    float cote;

public:
    BarreCarree(const float _densite, const float _longueur, const string _referenceBar, const float _cote);
    BarreCarree();
    BarreCarree(const BarreCarree &barreCarree);
    ~BarreCarree();

    float calculerMasse();
    float calculerSection();
};

#endif // BARRECARREE_H_INCLUDED
