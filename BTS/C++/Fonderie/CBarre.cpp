#include "CBarre.h"

CBarre::CBarre(const float _densite, const float _longueur, const string _referenceBar)
    : densite(_densite), longueur(_longueur), referenceBarre(_referenceBar)
{
    cout << "Je suis le constructeur a argument de Cbarre." << endl;
}

CBarre::CBarre()
    : densite(5), longueur(2), referenceBarre("none")
{
    cout << "Je suis le constructeur par defaut de Cbarre." << endl;
}

CBarre::CBarre(const CBarre &barre)
    : densite(barre.densite), longueur(barre.longueur), referenceBarre(barre.referenceBarre)
{
    cout << "Je suis le constructeur par copie de Cbarre." << endl;
}

CBarre::~CBarre()
{
    cout << "Barre detruite." << endl;
}

void CBarre::afficherReference()
{
    cout << "Reference :" << referenceBarre << endl;
}
