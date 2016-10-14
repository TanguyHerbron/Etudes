#include "CBarreRonde.h"
#include "CBarre.h"
#include <math.h>

CBarreRonde::CBarreRonde(const float _densite, const float _longueur, const string _referenceBarre, const float _rayon)
    : CBarre(_densite, _longueur, _referenceBarre), rayon(_rayon)
{
    cout << "Je suis le constructeur a argument de CBarreRonde." << endl;
}

CBarreRonde::CBarreRonde()
    : CBarre(), rayon(2)
{
    cout << "Je suis le constructeur par defaut de CBarreRonde." << endl;
}

CBarreRonde::CBarreRonde(const CBarreRonde &barreRonde)
{
    cout << "Je suis le constructeur par copie de CBarreRonde." << endl;
}

CBarreRonde::~CBarreRonde()
{
    cout << "BarreRonde detruite." << endl;
}

float CBarreRonde::calculerSection()
{
    return M_PI*rayon*rayon;
}

float CBarreRonde::calculerMasse()
{
    return longueur*densite*calculerSection();
}
