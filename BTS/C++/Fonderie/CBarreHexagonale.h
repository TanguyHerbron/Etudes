#ifndef CBARREHEXAGONALE_H_INCLUDED
#define CBARREHEXAGONALE_H_INCLUDED

#include "CBarre.h"

class CBarreHexagonale : public CBarre
{
private:
    float cote;

public:
    CBarreHexagonale(const float _densite, const float _longueur, const string _referenceBarre, const float _cote);
    CBarreHexagonale(const CBarreHexagonale &barreHexagonale);
    CBarreHexagonale();
    ~CBarreHexagonale();

    float calculerMasse();
    float calculerSection();
};



#endif // CBARREHEXAGONALE_H_INCLUDED
