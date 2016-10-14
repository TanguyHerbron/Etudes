#ifndef BARRE_H_INCLUDED
#define BARRE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Barre
{
protected:
    float densite;
    float longueur;
    string referenceBarre;

public:
    Barre(const float _densite, const float _longueur, const string _referenceBarre);
    Barre();
    Barre(const Barre &barre);

    virtual void afficherReference();

    virtual ~Barre();
    virtual float CalculerMasse() {return 0;}
};

#endif // BARRE_H_INCLUDED
