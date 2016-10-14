#include <iostream>

using namespace std;

int main()
{
    int nombre;
    string phrase;
    char car;

    //Entrer un nombre
    cout << "Entrer un nombre : " << endl;

    cin >> nombre;

    cout << "Vous avez entré " << nombre << "." << endl;

    //Entrer une phrase (Le premier caractère est manquant)
    cout << "Entrer une phrase : " << endl;

    do
    {
        cin >> car;
    }while(car == '\n');

    getline(cin, phrase);

    cout << "Vous avez entré la phrase \"" << phrase << "\".";

    return 0;
}
