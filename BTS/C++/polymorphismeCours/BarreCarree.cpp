#include "BarreCarree.h"
#include "Barre.h"

BarreCarree::BarreCarree(const float _densite, const float _longueur, const string _referenceBarre, const float _cote)
    : Barre(_densite, _longueur, _referenceBarre), cote(_cote)
{
cout << "Je suis le constructeur a argument de BarreCarree." << endl;
}

BarreCarree::BarreCarree()
    : Barre(), cote(2)
{
    cout << "Je suis le constructeur par defaut de BarreCarree." << endl;
}

BarreCarree::BarreCarree(const BarreCarree &barreCarree)
{
    cout << "Je suis le constructeur par copie de BarreCarree." << endl;
}

BarreCarree::~BarreCarree()
{
    cout << "BarreCarree detruite." << endl;
}

float BarreCarree::calculerSection()
{
    return cote*cote;
}

float BarreCarree::calculerMasse()
{
    return longueur*densite*calculerSection();
}
