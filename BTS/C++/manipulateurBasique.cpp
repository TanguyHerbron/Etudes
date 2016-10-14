#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double nombre = 12345.09876;
    double pi = 3.141592653;

    cout << "Avec un int" << endl;
    cout << 45 << endl;
    cout << hex << 45 << endl;
    cout << oct << 45 << endl;
    cout << dec << 45 << endl;

    cout << "Avec un double;" << endl;
    cout << nombre << endl;
    cout << fixed << nombre << endl;
    cout << scientific << nombre << endl;

    cout << fixed;

    cout << " Avec Pi" << endl;
    cout << pi << endl;
    cout << setprecision(0) << pi << endl;
    cout << setprecision(10) << pi << endl;

    return 0;
}
