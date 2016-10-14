#include <stdio.h>
#include <stdlib.h>
#define TAILLEMAX 255

int main()
{
    void exercice1(char phraseExo[TAILLEMAX])
    {
        char bonjour[] = "Bonjour";
        printf("\nVotre phrase est %s", phraseExo);

        //Le strlen permet de calculer la taille d'une chaine de caractères.
        printf("\nLa taille de votre phrase est égale à %d.\n", strlen(phraseExo));

        //Le strcomp permet de comparer entièrement deux chaines de caractères.
        if(strcmp(phraseExo, bonjour))
        {
            printf("Votre phrase est égale ou commence par \"Bonjour\".\n");
        }
        else
        {
            printf("Votre phrase n'est pas égale à \"Bonjour\".\n");
        }

        //Le strncomp permet de comparer deux chaines de caractères jusqu'à un index ou la fin d'une des chaines de caractère.
        if(strncmp(phraseExo, bonjour))
        {
            printf("Votre phrase commence par \"Bonjour\".\n");
        }
        else
        {
            printf("Votre phrase ne commence pas par \"Bonjour\".\n");
        }

        //Le strcpy permet de copier une chaine de caractère dans une autre.
        strcpy(phraseExo, bonjour);

        printf("La variable phraseExo[] contient maintenant \"%s\".\n", phraseExo);
    }

    void exercice2(char phraseExo[TAILLEMAX])
    {
        int boucle;
        int nbA = 0;
        for(boucle = 0; boucle < strlen(phraseExo); boucle++)
        {
            if(phraseExo[boucle] == 'a')
            {
                nbA++;
            }
        }

        printf("Il y a %d lettre a dans la phrase \"%s\".", nbA, phraseExo);
    }

    void exercice3(char phraseExo[TAILLEMAX])
    {
        int nBvoyelle = 0;
        int boucle;
        for(boucle = 0; boucle < strlen(phraseExo); boucle++)
        {
            if(phraseExo[boucle] == 'a' || phraseExo[boucle] == 'e' || phraseExo[boucle] == 'i' || phraseExo[boucle] == 'o' ||
               phraseExo[boucle] == 'u' || phraseExo[boucle] == 'y')
            {
                nBvoyelle++;
            }
        }
        printf("Il y a %d voyelle(s).\n", nBvoyelle);
    }

    void exercice4(char phraseExo[TAILLEMAX])
    {
        int nBconsonne = 0;
        int boucle;
        for(boucle = 0; boucle < strlen(phraseExo); boucle++)
        {
            if((phraseExo[boucle] >= 'a' && phraseExo[boucle] <= 'z') || (phraseExo[boucle] >= 'A' && phraseExo[boucle] <= 'Z'))
            {
                if(phraseExo[boucle] != 'a' && phraseExo[boucle] != 'A' && phraseExo[boucle] != 'e' && phraseExo[boucle] != 'E' &&
                   phraseExo[boucle] != 'i' && phraseExo[boucle] != 'I' && phraseExo[boucle] != 'o' && phraseExo[boucle] != 'O' &&
                   phraseExo[boucle] != 'u' && phraseExo[boucle] != 'U' && phraseExo[boucle] != 'y' && phraseExo[boucle] != 'Y')
                {
                    nBconsonne++;
                }
            }
        }
        printf("Il y a %d consonne(s).\n", nBconsonne);
    }

    void exercice5(char phraseExo[TAILLEMAX])
    {
        int nBmot = 0;
        int boucle;
        for(boucle = 0; boucle < strlen(phraseExo); boucle++)
        {
            if((phraseExo[boucle] >= 'a' && phraseExo[boucle] <= 'z') || (phraseExo[boucle] >= 'A' && phraseExo[boucle] <= 'Z'))
            {
                if((phraseExo[boucle + 1] >= ' ' && phraseExo[boucle+1] <= '/') ||
                   (phraseExo[boucle + 1] >= ':' && phraseExo[boucle+1] <= '@') ||
                   (phraseExo[boucle + 1] >= '[' && phraseExo[boucle+1] <= '`') || phraseExo[boucle+1]=='\0')
                {
                    nBmot++;
                }
            }
        }
        printf("Il y a %d mot(s) dans votre phrase.", nBmot);
    }

    void exercice6(char phraseExo[TAILLEMAX])
    {
        int boucle;
        printf("Votre phrase à l'envers donne :\n");
        for(boucle = strlen(phraseExo); boucle >= 0; boucle--){
            printf("%c", phraseExo[boucle]);
        }
        printf("\n");
    }

    void exercice7(char phraseExo[TAILLEMAX])
    {
        char phraseExoInversion[TAILLEMAX];
        int boucle = 0;
        for(boucle = 0; boucle < strlen(phraseExo); boucle++)
        {
            if(phraseExo[boucle] >= 'a' && phraseExo[boucle] <= 'z')
            {
                phraseExoInversion[boucle] = phraseExo[boucle] - ('a'-'A');
            }
            if(phraseExo[boucle] >= 'A' && phraseExo[boucle] <= 'Z')
            {
                phraseExoInversion[boucle] = phraseExo[boucle] - ('A' - 'a');
            }
        }
        printf("%s\n", phraseExoInversion);
    }

    char phrase[TAILLEMAX];
    int exo;
    printf("Saisissez une phrase : ");
    gets(phrase);

    printf("Avec quel exercice voulez-vous traiter cette phrase ?\n");
    printf("1- Exemple des différentes fonctions str.\n");
    printf("2- Comptage du nombre de a dans une phrase.\n");
    printf("3- Comptage du nombre de voyelle dans une phrase.\n");
    printf("4- Comptage du nombre de consonne dans une phrase.\n");
    printf("5- Comptage du nombre de mot dans une phrase.\n");
    printf("6- Lire la phrase dans l'ordre inverse.\n");
    printf("7- Inverser majuscule et minuscule.\n");
    printf("Choix :");
    scanf("%d", &exo);

    switch (exo)
    {
    case 1:
        exercice1(phrase);
        break;
    case 2:
        exercice2(phrase);
        break;
    case 3:
        exercice3(phrase);
        break;
    case 4:
        exercice4(phrase);
        break;
    case 5:
        exercice5(phrase);
        break;
    case 6:
        exercice6(phrase);
        break;
    case 7:
        exercice7(phrase);
        break;
    default:
        printf("Il n'y a pas d'exercice pour cette valeur.");
    }
}
