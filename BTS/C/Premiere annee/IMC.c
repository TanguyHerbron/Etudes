//Herbron Tanguy
//Calcul de l'IMC

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nom[100];
    char prenom[100];
    char sexe;
    char choixFormule;
    float age;
    int menu = 0;
    float taille;
    float poids;
    float imc;
    float poidsIdeal;

    printf("Bienvenue dans notre programme de calcul de l'IMC.\n");
    printf("Nous avons besoin de quelques renseignements.\n");
    printf("Votre nom: ");
    gets(nom);
    printf("Votre prénom: ");
    gets(prenom);
    printf("Votre sexe (h ou f): ");
    scanf(" %c", &sexe);
    while(sexe != 'h' && sexe != 'f')
    {
        printf("Saisie incorrecte, réessayez.\n");
        printf("Votre sexe (h ou f): ");
        scanf(" %c", &sexe);
    }
    printf("Votre age: ");
    scanf("%d", &age);
    printf("Votre taille (en mètre): ");
    scanf("%f", &taille);
    printf("Votre poids (en kg): ");
    scanf("%f", &poids);
    printf("\n");

    printf("Votre fiche récapitulative :\n");
    printf("- Identite   : %s %s\n", prenom, nom);
    printf("- Age        : %.0f ans\n", age);
    printf("- Poids      : %.2f kg\n", poids);
    printf("- Taille     : %.2f m\n", taille);

    //Vérification du sexe pour une écriture plus correcte
    if(sexe == 'h')
    {
        printf("- Sexe       : homme\n\n");
    }
    else
    {
        printf("- Sexe       : femme\n\n");
    }

    imc = poids / (taille * taille);

    //Correspondance de la corpulence en fonction de l'IMC
    if(imc <= 16.5)
    {
        printf("Votre indice de masse corporelle est de %.1f.\n", imc);
        printf("Votre corpulence est qualifiée de famine.\n");
    }
    else
    {
        if(imc <= 18.5)
        {
            printf("Votre indice de masse corporelle est de %.1f.\n", imc);
            printf("Votre corpulence est qualifiée de maigreur.\n");
        }
        else
        {
            if(imc <= 25)
            {
                printf("Votre indice de masse corporelle est de %.1f.\n", imc);
                printf("Votre corpulence est qualifiée de normale.\n");
            }
            else
            {
                if(imc <= 30)
                {
                    printf("Votre indice de masse corporelle est de %.1f.\n", imc);
                    printf("Votre corpulence est qualifiée de surpoids.\n");
                }
                else
                {
                    if(imc <= 35)
                    {
                        printf("Votre indice de masse corporelle est de %.1f.\n", imc);
                        printf("Votre corpulence est qualifiée de obésité modéré.\n");
                    }
                    else
                    {
                        if(imc <= 40)
                        {
                            printf("Votre indice de masse corporelle est de %.1f.\n", imc);
                            printf("Votre corpulence est qualifiée de obésité sévère.\n");
                        }
                        else
                        {
                            printf("Votre indice de masse corporelle est de %.1f.\n", imc);
                            printf("Votre corpulence est qualifiée de obésité morbide.\n");
                        }
                    }
                }
            }
        }
    }

    printf("\n");

    do
    {
        printf("Calculez votre poids idéal :\n");
        printf("a - formule de Lorents\n");
        printf("b - formule de Devine\n");
        printf("c - formule de Lorents en tenant compte de l'age\n");
        printf("q - quitter le menu de calcul du poids idéal\n");
        printf("Votre choix: ");
        scanf(" %c", &choixFormule);

        //Menu pour choisir le mode de calcul du poids idéal
        switch (choixFormule)
        {
        case 'a':
            if(sexe == 'h')
            {

            }

            printf("Votre poids idéal selon la formule de Lorents est de %.1f kg.\n\n", poidsIdeal);
            break;
        case 'b':
            if(sexe == 'h')
            {
                poidsIdeal = 50 + 2.3 * (taille / 0.0254 - 60);
            }
            else
            {
                poidsIdeal = 45.5 + 2.3 * (taille / 0.0254 - 60);
            }
            printf("Votre poids idéal selon la formule de Devine est de %.1f kg.\n\n", poidsIdeal);
            break;
        case 'c':
            poidsIdeal = 50 + ((taille * 100 - 150) / 4) + ((age - 20) / 4);
            printf("Votre poids idéal selon la formule de Lorents en tenant compte de l'age est de %.1f kg.\n\n", poidsIdeal);
            break;
        case 'q':
            printf("Vous avez quitté le menu de calcul du poids idéal.\n");
            menu++;
            break;
        default:
            printf("Caractère entré incorrecte. Réessayez.\n\n");
        }
    }
    while (menu == 0);
}
