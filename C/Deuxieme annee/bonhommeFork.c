#include <stdio.h>
#include <stdlib.h>

//Les variables testFourchetteX correspondent aux fourchette de séparation d'un processus.

int main()
{
    int testFourchette1, testFourchette2, testFourchette3, testFourchette4, testFourchette5, testFourchette6;
    testFourchette1 = fork();
    if(testFourchette1 == 0) //Je suis P3, l'enfant de P1
    {
        boite("Boite 3");
        testFourchette2 = fork();
        if(testFourchette2 == 0) //Je suis P2, l'enfant de P3
        {
            boite("Boite 2");
        }
        else //Je suis P3
        {
            testFourchette3 = fork();
            if(testFourchette3 == 0) //Je suis P4, l'enfant de P3
            {
                boite("Boite 4");
            }
            else //Je suis P3, l'enfant de P1
            {
                testFourchette4 = fork();
                if(testFourchette4 == 0) //Je suis P5, l'enfant de P3
                {
                    boite("Boite 5");
                    testFourchette5 = fork();
                    if(testFourchette5 == 0) //Je suis P6, l'enfant de P5
                    {
                        boite("Boite 6");
                    }
                    else //Je suis P5, l'enfant de P3
                    {
                        testFourchette6 = fork();
                        if(testFourchette6 == 0) //Je suis P7, l'enfant de P5
                        {
                            boite("Boite 7");
                        }
                        else //Je suis P5, l'enfant de P3
                        {
                            boite("Boite 5");
                        }
                    }
                }
                else //Je suis P3, l'enfant de P1
                {
                    boite("Boite 3");
                }
            }
        }
    }
    else //Je suis P1
    {
        boite("Boite 1");
    }
    return EXIT_SUCCESS;
}
