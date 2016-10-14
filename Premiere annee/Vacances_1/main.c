#include <stdio.h>
#include <stdlib.h>

int main()
{
    void affichageDate(int jour, int mois, int annee){
        int choix;

        do{
            printf("Format d'affichage de votre date de naissance :\n");
            printf("1 - jj/mm/aaaa\n");
            printf("2 - jj-mm-aaaa\n");
            printf("3 - jj:mm:aaaa\n");
            printf("4 - jj.mm.aaaa\n");
            printf("Choisissez le format d'affichage (1,2,3 ou 4) : ");
            scanf("%d", &choix);

            switch (choix){
            case 1:
                printf("Votre date de naissance est le %d/%d/%d.\n", jour, mois, annee);
                break;
            case 2:
                printf("Votre date de naissance est le %d-%d-%d.\n", jour, mois, annee);
                break;
            case 3:
                printf("Votre date de naissance est le %d:%d:%d.\n", jour, mois, annee);
                break;
            case 4:
                printf("Votre date de naissance est le %d.%d.%d.\n", jour, mois, annee);
                break;
            default :
                printf("Votre choix n'est pas correcte, réessayez.\n");
            }
        }while(choix != 1 || choix != 2 || choix != 3 || choix != 4);
    }

    int jour = 17;
    int moisNum = 12;
    int annee = 1991;

    char nom[50] = "Herbron";
    char prenom[50] = "Tanguy";

    /*printf("Jour de naissance : ");
    scanf("%d", &jour);
    printf("Mois de naissance : ");
    scanf("%d", &moisNum);
    printf("Année de naissance : ");
    scanf("%d", &annee);
    printf("\n");

    printf("Votre date de naissance est le %d/%d/%d.\n\n", jour, moisNum, annee);

    printf("Votre nom : ");
    scanf("%s", nom);
    printf("Votre prénom : ");
    scanf("%s", prenom);
    printf("\n");*/

    printf("Bonjour %s %s.\n\n", prenom, nom);

    if(annee >= 1995){
        printf("Désolé, vous êtes trop jeune pour continuer.");
    }else{
        printf("Vous êtes autorisé à continuer.");
        affichageDate(jour, moisNum, annee);
    }

    return 0;
}
