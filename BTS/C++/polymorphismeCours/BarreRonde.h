#ifndef BARRERONDE_H_INCLUDED
#define BARRERONDE_H_INCLUDED

#include "Barre.h"

class BarreRonde : public Barre
{
private:
    float rayon;

public:
    BarreRonde(const float _densite, const float _longueur, const string _referenceBarre, const float _rayon);
    BarreRonde(const BarreRonde &barreRonde);
    BarreRonde();
    ~BarreRonde();

    float calculerMasse();
    float calculerSection();
};

#endif // BARRERONDE_H_INCLUDED
