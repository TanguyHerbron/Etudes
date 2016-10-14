#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setfill('.');
    for (int i = 0; i < 10; i++)
    {
        if (i%2)
            cout << "|" << left << setw(5) << i << "|" << endl;
        else
            cout << "|" << right << setw(5) << i << "|" << endl;

    }
    return 0;
}
