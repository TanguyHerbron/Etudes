#ifndef CBARRERONDE_H_INCLUDED
#define CBARRERONDE_H_INCLUDED

#include "CBarre.h"

class CBarreRonde : public CBarre
{
private:
    float rayon;

public:
    CBarreRonde(const float _densite, const float _longueur, const string _referenceBarre, const float _rayon);
    CBarreRonde(const CBarreRonde &barreRonde);
    CBarreRonde();
    ~CBarreRonde();

    float calculerMasse();
    float calculerSection();
};



#endif // CBARRERONDE_H_INCLUDED
