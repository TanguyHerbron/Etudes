#ifndef CADRAN_H
#define CADRAN_H
#include <string>
#include <unistd.h>
#include <cstdio>
#define LAG 100000 //Temps de latence en ms

using namespace std;

class Cadran
{
    public:
        Cadran(const int _posX = 1, const int _posY = 1,const int _hauteur = 2, const int _largeur = 10);
        virtual ~Cadran();
        void Afficher(const string _texte, const int _position = 2);
        void Afficher(const int _valeur, const int _position = 2);
     private:
        void GotoXY(const int _x, const int _y);
        int posX;
        int posY;
        int hauteur;
        int largeur;
};

#endif // CADRAN_H
