#include "Cadran.h"
#include <iostream>
#include <iomanip>

 using namespace std;

Cadran::Cadran(const int _posX, const int _posY,const int _hauteur, const int _largeur):
   posX(_posX),
   posY(_posY),
   hauteur(_hauteur),
   largeur(_largeur)
{
    int i = 0;
    cout << setfill('-');
    GotoXY(posX, posY + i);
    cout << "+" << setw(largeur) << "+";
    cout << setfill(' ');
    for(i = 1; i <= hauteur; i++)
    {
        GotoXY(posX, posY + i);
        cout << "+" << setw(largeur) << "+";
    }
    cout << setfill('-');
    GotoXY(posX, posY + i);
    cout << "+" << setw(largeur) << "+";

}
Cadran::~Cadran()
{
    GotoXY(15,15);
}
void Cadran::Afficher(const int _valeur, const int _position) //Affichage d'un entier donné en paramètre à une position donnée en paramètre
{

    GotoXY(posX+1+_position,posY+1);
    cout << setfill('0');
    cout << setw(2);
    cout << _valeur;
}
void Cadran::Afficher(const string _texte, const int _position) //Affichage d'une chaine de caractère donnée en paramètre à une position donnée en paramètre
{
    GotoXY(posX+1+_position,posY+1);
    cout << _texte ;
}
void Cadran::GotoXY(const int _x,const int _y) //Déplace le curseur d'écriture dans la console
{
    /*COORD coord;
    coord.X = _x;
    coord.Y = _y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);*/
    printf("%c[%d;%df", 0x1B, _x, _y);
}
