#include <stdio.h>
#include <stdlib.h>



int main()
{
    int boucle = 0;
    while(!boucle){
        int numeroExercice;
        printf("Quel exercice voulez vous essayez ?\n\n");
        printf("Exercice 1 : Addition\n");
        printf("Exercice 2 : Division\n");
        printf("Exercice 3 : Acquisition caractères\n\n");
        printf("Numéro de l'exercice demandé: ");
        scanf("%d", &numeroExercice);

        if(numeroExercice == 1){

            printf("\n\n");
            printf("EXERCICE 1\n\n\n");

            float premier_entier;
            float second_entier;

            printf("Premier chiffre: ");
            scanf("%f", &premier_entier);
            printf("Second chiffre: ");
            scanf("%f", &second_entier);
            printf("\n");
            float resultat = premier_entier + second_entier;
            printf("La somme est %f.\n\n\n",resultat);

            printf("Voules-vous quitter le programme ?\n");
            printf("0 - Non\n");
            printf("1 - Oui\n");
            printf("Votre choix: ");
            scanf("%d", &boucle);

        }else if(numeroExercice == 2){

            printf("\n\n");
            printf("EXERCICE 2\n\n\n");

            float divise;
            float diviseur;

            printf("Chiffre à divisé: ");
            scanf("%f", &divise);
            printf("Chiffre diviseur: ");
            scanf("%f", &diviseur);
            printf("\n");
            if(diviseur != 0){

                float resultat = divise / diviseur;
                printf("La division de %f par %f est %f.\n\n\n" ,divise, diviseur, resultat);

                printf("Voules-vous quitter le programme ?\n");
                printf("0 - Non\n");
                printf("1 - Oui\n");
                printf("Votre choix: ");
                scanf("%d", &boucle);

            }else{

                printf("Le diviseur est nul, la division est donc impossible.\n\n");

                printf("Voules-vous quitter le programme ?\n");
                printf("0 - Non\n");
                printf("1 - Oui\n");
                printf("Votre choix: ");
                scanf("%d", &boucle);
            }

        }else if(numeroExercice == 3){

            printf("\n\n");
            printf("EXERCICE 3\n\n\n");

            char nom [80];
            char prenom [80];

            printf("Votre nom est: ");
            scanf("%79s", nom);
            printf("Votre prenom est: ");
            scanf("%79s", prenom);
            printf("\n");
            printf("Bonjour %s %s.\n\n\n" ,prenom, nom);

            printf("Voules-vous quitter le programme ?\n");
            printf("0 - Non\n");
            printf("1 - Oui\n");
            printf("Votre choix: ");
            scanf("%d", &boucle);

        }else{
            printf("\n");
            printf("Il n'y a pas d'exercice %d.\n", numeroExercice);
            printf("\n");

            printf("Voules-vous quitter le programme ?\n");
            printf("0 - Non\n");
            printf("1 - Oui\n");
            printf("Votre choix: ");
            scanf("%d", &boucle);
        }
    }

}
