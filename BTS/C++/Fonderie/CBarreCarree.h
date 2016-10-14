#ifndef CBARRECARREE_H_INCLUDED
#define CBARRECARREE_H_INCLUDED

#include "CBarre.h"

class CBarreCarree : public CBarre
{
private:
    float cote;

public:
    CBarreCarree(const float _densite, const float _longueur, const string _referenceBar, const float _cote);
    CBarreCarree();
    CBarreCarree(const CBarreCarree &barreCarree);
    ~CBarreCarree();

    float calculerMasse();
    float calculerSection();
};

#endif // CBARRECARREE_H_INCLUDED
