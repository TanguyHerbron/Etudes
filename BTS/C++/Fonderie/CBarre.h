#ifndef CBARRE_H_INCLUDED
#define CBARRE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class CBarre
{
protected:
    float densite;
    float longueur;
    string referenceBarre;

public:
    CBarre(const float _densite, const float _longueur, const string _referenceBarre);
    CBarre();
    CBarre(const CBarre &barre);

    void afficherReference();

    ~CBarre();
};

#endif // CBARRE_H_INCLUDED
