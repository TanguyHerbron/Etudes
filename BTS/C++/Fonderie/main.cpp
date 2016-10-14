#include <iostream>
#include "CBarre.h"
#include "CBarreCarree.h"
#include "CBarreHexagonale.h"
#include "CBarreRectangle.h"
#include "CBarreRonde.h"

using namespace std;

int main()
{
    CBarreCarree *barreCarree1 = new CBarreCarree(8.9, 4, "barreCarree", 2);

    CBarreHexagonale *barreHexagonale1 = new CBarreHexagonale(19.8, 651, "barreHexagonale", 5.6);

    CBarreRectangle *barreRectangle1 = new CBarreRectangle(19.8, 15.2, "b", 20.8, 60.5);

    CBarreRonde *barreRonde1 = new CBarreRonde(11.3, 12, "barreRonde", 3.14);

    barreHexagonale1->afficherReference();
    cout << "Masse :" << barreHexagonale1->calculerMasse() << endl;

    barreCarree1->afficherReference();
    cout << "Masse :" << barreCarree1->calculerMasse() << endl;

    barreRectangle1->afficherReference();
    cout << "Masse :" << barreRectangle1->calculerMasse() << endl;

    barreRonde1->afficherReference();
    cout << "Masse :" << barreRonde1->calculerMasse() << endl;

    delete barreHexagonale1;

    delete barreCarree1;

    delete barreRectangle1;

    delete barreRonde1;

    return 0;
}
