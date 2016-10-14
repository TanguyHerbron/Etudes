#include "CBarreRectangle.h"
#include "CBarre.h"

CBarreRectangle::CBarreRectangle(const float _densite, const float _longueur, const string _referenceBarre, const float _hauteur, const float _largeur)
    : CBarre(_densite, _longueur, _referenceBarre), hauteur(_hauteur), largeur(_largeur)
{
cout << "Je suis le constructeur a argument de CBarreRectangle." << endl;
}

CBarreRectangle::CBarreRectangle(const CBarreRectangle &barreRectangle)
{
    cout << "Je suis le constructeur par copie de CBarreRectangle." << endl;
}

CBarreRectangle::CBarreRectangle()
    : CBarre(), hauteur(5), largeur(5)
{
    cout << "Je suis le constructeur par defaut de CBarreRectangle." << endl;
}

CBarreRectangle::~CBarreRectangle()
{
    cout << "BarreRectangle detruite." << endl;
}

float CBarreRectangle::calculerSection()
{
    return largeur*hauteur;
}

float CBarreRectangle::calculerMasse()
{
    return longueur*densite*calculerSection();
}
