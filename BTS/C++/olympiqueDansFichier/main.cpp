#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <errno.h>

using namespace std;

int main()
{
    string inputFile;
    string pays;
    char tmp;
    int nbOr;
    int nbArgent;
    int nbBronze;

    cout << "Entrer le nom du fichier a lire : ";

    cin >> inputFile;

    ifstream fichier(inputFile.c_str()); //Creation du flux en lecture du fichier
    ofstream output("nouveau.txt");

    if(errno != 0)
    {
        cerr << "Erreur lors de l'ouverture : " << errno;
        return errno;
    }

    cout << setfill('-');
    output << setfill('-');

    //affichage de la premiere ligne du tableau
    cout << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
    output << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
    cout << setfill(' ');
    output << setfill(' ');

    while(fichier) //Tant que le fichier n'est pas fini
    {
        fichier >> pays >> nbOr >> nbArgent >> nbBronze; //recuperation des valeurs
        if(fichier)//Si le fichier peut etre lu
        {
            //affichage des lignes du tableau
            cout << "| " << left << setw(16) << pays << "|" << right << setw(7) << nbOr << " |" << right << setw(7) << nbArgent << " |" << right << setw(7) << nbBronze << " |" << endl;
            output << "| " << left << setw(16) << pays << "|" << right << setw(7) << nbOr << " |" << right << setw(7) << nbArgent << " |" << right << setw(7) << nbBronze << " |" << endl;
        }
    }
    //Affichage du bas du tableau.
    cout << setfill('-');
    output << setfill('-');
    cout << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;
    output << "+" << setw(18) << "+" << setw(9) << "+" << setw(9) << "+" << setw(9) << "+" << endl;

    return 0;
}
