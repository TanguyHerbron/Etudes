#include <iostream>
#include "cadran.h"
#include "clavier.h"
#include "horloge.h"
#include "reveil.h"

using namespace std;

int main()
{

    Reveil *monReveil = new Reveil();

    monReveil->Controler();

    return 0;
}
