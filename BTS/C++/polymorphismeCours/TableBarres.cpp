#include "TableBarres.h"


TableBarres::TableBarres(short _taille)
    :taille(_taille)
{
    index = 0 ;
    table = new Barre*[taille];
}

TableBarres::~TableBarres()
{
    delete[] table ;
}

void TableBarres::add(Barre *pBarre)
{
    if (index < taille)
        table[index++] = pBarre ;
}

void TableBarres::AfficherCatalogue()
{
    for (short indice = 0 ; indice < index ; indice++)
    {
        table[indice]->afficherReference();
        cout << table[indice]->CalculerMasse(); //erreur de compilation
    }
}
