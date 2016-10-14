#ifndef CBARRERECTANGLE_H_INCLUDED
#define CBARRERECTANGLE_H_INCLUDED

#include "CBarre.h"

class CBarreRectangle : public CBarre
{
private:
    float hauteur;
    float largeur;

public:
    CBarreRectangle(const float _densite, const float _longueur, const string _referenceBarre, const float _hauteur, const float _largeur);
    CBarreRectangle(const CBarreRectangle &barreRectangle);
    CBarreRectangle();
    ~CBarreRectangle();

    float calculerMasse();
    float calculerSection();
};



#endif // CBARRERECTANGLE_H_INCLUDED
