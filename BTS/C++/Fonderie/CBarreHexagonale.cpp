#include "CBarreHexagonale.h"
#include "CBarre.h"
#include <math.h>

CBarreHexagonale::CBarreHexagonale(const float _densite, const float _longueur, const string _referenceBarre, const float _cote)
    : CBarre(_densite, _longueur, _referenceBarre), cote(_cote)
{
cout << "Je suis le constructeur a argument de CBarreHexagonale." << endl;
}

CBarreHexagonale::CBarreHexagonale(const CBarreHexagonale &barreHexagonale)
{
    cout << "Je suis le constructeur par copie de CBarreHexagonale." << endl;
}

CBarreHexagonale::CBarreHexagonale()
    : CBarre(), cote(2)
{
    cout << "Je suis le constructeur par defaut de CBarreHexagonale." << endl;
}

CBarreHexagonale::~CBarreHexagonale()
{
    cout << "BarreHexagonale detruite." << endl;
}

float CBarreHexagonale::calculerSection()
{
    return (3*sqrt(3)/2)*cote;
}

float CBarreHexagonale::calculerMasse()
{
    return longueur*densite*calculerSection();
}
