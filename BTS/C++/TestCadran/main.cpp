#include <iostream>
#include "Cadran.h"

using namespace std;

int main()
{
    Cadran leCadran;
    Cadran leCadran0(15, 1);
    for(int i = 1; i <= 10; i++)
    {
        leCadran.Afficher(i, 5);
        usleep(LAG);
    }
    leCadran.Afficher("Fin", 2);

    for(int i = 1; i <= 15; i++)
    {
        leCadran0.Afficher(i, 5);
        usleep(LAG);
    }
    leCadran.Afficher("Termine", 15);
    return 0;
}
