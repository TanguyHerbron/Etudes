#include "CBarreCarree.h"
#include "CBarre.h"

CBarreCarree::CBarreCarree(const float _densite, const float _longueur, const string _referenceBarre, const float _cote)
    : CBarre(_densite, _longueur, _referenceBarre), cote(_cote)
{
cout << "Je suis le constructeur a argument de CBarreCarree." << endl;
}

CBarreCarree::CBarreCarree()
    : CBarre(), cote(2)
{
    cout << "Je suis le constructeur par defaut de CBarreCarree." << endl;
}

CBarreCarree::CBarreCarree(const CBarreCarree &barreCarree)
{
    cout << "Je suis le constructeur par copie de CBarreCarree." << endl;
}

CBarreCarree::~CBarreCarree()
{
    cout << "BarreCarree detruite." << endl;
}

float CBarreCarree::calculerSection()
{
    return cote*cote;
}

float CBarreCarree::calculerMasse()
{
    return longueur*densite*calculerSection();
}
