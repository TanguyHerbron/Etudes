#include <iostream>
#include "TableBarres.h"
#include "BarreRonde.h"

using namespace std;

int main()
{
    TableBarres *tableBarre = new TableBarres(10);

    tableBarre->add(new BarreRonde(6.2, 5, "coucou", 3));

    tableBarre->AfficherCatalogue();


    return 0;
}
