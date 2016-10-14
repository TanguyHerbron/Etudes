#include "Barre.h"

Barre::Barre(const float _densite, const float _longueur, const string _referenceBar)
    : densite(_densite), longueur(_longueur), referenceBarre(_referenceBar)
{
    cout << "Je suis le constructeur a argument de Barre." << endl;
}

Barre::Barre()
    : densite(5), longueur(2), referenceBarre("none")
{
    cout << "Je suis le constructeur par defaut de Barre." << endl;
}

Barre::Barre(const Barre &barre)
    : densite(barre.densite), longueur(barre.longueur), referenceBarre(barre.referenceBarre)
{
    cout << "Je suis le constructeur par copie de Barre." << endl;
}

Barre::~Barre()
{
    cout << "Barre detruite." << endl;
}

void Barre::afficherReference()
{
    cout << "Reference :" << referenceBarre << endl;
}
