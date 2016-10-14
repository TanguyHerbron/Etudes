#include "BarreRonde.h"
#include "Barre.h"
#include <math.h>

BarreRonde::BarreRonde(const float _densite, const float _longueur, const string _referenceBarre, const float _rayon)
    : Barre(_densite, _longueur, _referenceBarre), rayon(_rayon)
{
    cout << "Je suis le constructeur a argument de BarreRonde." << endl;
}

BarreRonde::BarreRonde()
    : Barre(), rayon(2)
{
    cout << "Je suis le constructeur par defaut de BarreRonde." << endl;
}

BarreRonde::BarreRonde(const BarreRonde &barreRonde)
{
    cout << "Je suis le constructeur par copie de BarreRonde." << endl;
}

BarreRonde::~BarreRonde()
{
    cout << "BarreRonde detruite." << endl;
}

float BarreRonde::calculerSection()
{
    return M_PI*rayon*rayon;
}

float BarreRonde::calculerMasse()
{
    return longueur*densite*calculerSection();
}
