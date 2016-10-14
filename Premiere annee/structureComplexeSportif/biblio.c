#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "biblio.h"

void effacerEcran()
{
    printf("%c[2J", 0x1B);
    printf("\033[100A");
    printf("\033[100D", 0x1B);
    printf("BASE DE DONNEE COMPLEXE SPORTIF\n\n");
}

void testerOuvertureFichier()
{
    if(errno != NULL)
    {
        printf("Erreur fichier : erreur n'%d\n", errno);
        exit(0);
    }
}

void afficherMenu(int compteurAdherent)
{
    printf("Que voulez-vous faire ?\n");

    if(compteurAdherent == 0)
    {
        printf("A- Ajouter une fiche adherent\n");
        printf("Q- Quitter\n");
    }
    else
    {
        printf("A : Ajouter une fiche adherent\n");
        printf("S : Supprimer une fiche\n");
        printf("M : Modifier une fiche\n");
        printf("V : Voir le contenu d'une fiche\n");
        printf("L : Voir le contenu de l'ensemble des fiches\n");
        printf("E : Supprimer toutes les fiches\n");
        printf("X : Exporter adherents\n");
        printf("Q : Quitter\n");
    }
    printf("Votre choix :");
}

void afficherDate(date dateAfficher)
{
    printf("%d/%d/%d", dateAfficher.jour, dateAfficher.mois, dateAfficher.annee);
}

void afficherActivite(sport listSport)
{
    switch (listSport)
    {
    case NATATION:
        printf("Natation\n");
        break;
    case BASKETBALL:
        printf("Basketball\n");
        break;
    case HANDBALL:
        printf("Handball\n");
        break;
    case SQUASH:
        printf("Squash\n");
        break;
    case TENNIS:
        printf("Tennis\n");
        break;
    }
}

typeAdherent *creerUnAdherent()
{
    typeAdherent *adherent;
    int i, numSport;

    adherent = (typeAdherent*) malloc(sizeof(typeAdherent));
    printf("Nom :");
    scanf("%s", adherent->nom);
    printf("Prenom :");
    scanf("%s", adherent->prenom);
    printf("Date de naissance :");
    printf("\n\tJour :");
    scanf("%d", &adherent->dateDeNaissance.jour);
    printf("\tMois :");
    scanf("%d", &adherent->dateDeNaissance.mois);
    printf("\tAnnee :");
    scanf("%d", &adherent->dateDeNaissance.annee);
    printf("Numero d'adherent :");
    scanf("%d", &adherent->numCarte);
    printf("Nombre d'activite :");
    scanf("%d", &adherent->nbActivite);
    for(i = 0; i < adherent->nbActivite; i++)
    {
        printf("Quel sport voulez-vous faire ?\n");
        printf("1- Natation\n");
        printf("2- Basket\n");
        printf("3- Hand\n");
        printf("4- Squash\n");
        printf("5- Tennis\n");
        printf("Votre choix : ");
        scanf("%d", &numSport);

        switch (numSport)
        {
        case 1:
            adherent->activite[i] = NATATION;
            break;
        case 2:
            adherent->activite[i] = BASKETBALL;
            break;
        case 3:
            adherent->activite[i] = HANDBALL;
            break;
        case 4:
            adherent->activite[i] = SQUASH;
            break;
        case 5:
            adherent->activite[i] = TENNIS;
            break;
        }
    }
    return adherent;
}

void afficherUnAdherent(typeAdherent *adherent[], int numeroCarte, int nb)
{
    int i, j;
    for(j = 0; j < nb; j++)
    {
        if(numeroCarte == adherent[j]->numCarte)
        {
            printf("\nNom : %s", adherent[j]->nom);
            printf("\nPrenom : %s", adherent[j]->prenom);
            printf("\nDate de naissance : %d/%d/%d", adherent[j]->dateDeNaissance.jour, adherent[j]->dateDeNaissance.mois, adherent[j]->dateDeNaissance.annee);
            printf("\nNombre d'activite : %d\n", adherent[j]->nbActivite);
            for(i = 0; i < adherent[j]->nbActivite; i++)
            {
                afficherActivite(adherent[j]->activite[i]);
            }
        }
    }
}

void afficherAdherents(typeAdherent *ad[], int nb)
{
    int i, j;
    printf("╔════════════════════╦════════════════════╦══════════╦═══════════════════════════════════╗\n");
    printf("║Nom                 ║Prenom              ║Naissance ║Activités                          ║\n");
    for(j = 0; j < nb; j++)
    {
        printf("╠════════════════════╬════════════════════╬══════════╬═══════════════════════════════════╣\n");
        printf("║%20s", ad[j]->nom);
        printf("║%20s", ad[j]->prenom);
        printf("║%2d/%2d/%2d║", ad[j]->dateDeNaissance.jour, ad[j]->dateDeNaissance.mois, ad[j]->dateDeNaissance.annee);
        for(i = 0; i < ad[j]->nbActivite; i++)
        {
            switch (ad[j]->activite[i])
            {
            case NATATION:
                printf("Natation ");
                break;
            case BASKETBALL:
                printf("Basket ");
                break;
            case HANDBALL:
                printf("Hand ");
                break;
            case SQUASH:
                printf("Squash ");
                break;
            case TENNIS:
                printf("Tennis ");
                break;
            }
        }
        printf("\033[100D");
        printf("\033[89C");
        printf("║\n");
    }
    printf("╚════════════════════╩════════════════════╩══════════╩═══════════════════════════════════╝\n");
}

int ajouterUnAdherent(typeAdherent *tab[], int nb)
{
    tab[nb] = creerUnAdherent();
    nb++;
    return nb;
}

int supprimerUnAdherent(typeAdherent *tab[], int nro, int nb)
{
    int i, j;

    for(i = 0; i < nb; i++)
    {
        if(tab[i]->numCarte == nro)
        {
            //free(tab[i]);

            for(j = i; j < nb; j++)
            {
                tab[j] = tab[j+1];
            }
        }
    }
    nb--;
    return nb;
}

int supprimerAdherents(typeAdherent *tab[], int nb)
{
    int i;

    for(i = 0; i < nb; i++)
    {
        free(tab[i]);
    }
    return 0;
}

void modifierFiche(typeAdherent *tab[], int nro, int nb)
{
    int i;
    int choix;

    for(i = 0; i < nb; i++)
    {
        if(tab[i]->numCarte == nro)
        {
            do
            {
                printf("Quel paramètre voulez-vous modifier ?\n");
                printf("1- Nom\n");
                printf("2- Prenom\n");
                printf("3- Date de naissance\n");
                printf("4- Nombre d'activité\n");
                printf("5- Quitter\n");
                printf("Votre choix :");
                scanf("%d", &choix);

                switch (choix)
                {
                case 1:
                    printf("Nouveau nom :");
                    scanf("%s", tab[i]->nom);
                    break;
                case 2:
                    printf("Nouveau prenom :");
                    scanf("%s", tab[i]->prenom);
                    break;
                case 3:
                    printf("Nouveau jour de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.jour);
                    printf("Nouveau mois de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.mois);
                    printf("Nouvelle annee de naissance :");
                    scanf("%d", &tab[i]->dateDeNaissance.annee);
                    break;
                case 4:
                    printf("Nouveau nombre d'activite :");
                    scanf("%d", &tab[i]->nbActivite);
                    break;
                }
            }
            while(choix != 5);
        }
    }
}

void sauvegardeAdherents(typeAdherent *ad[], int nb)
{
    char nomFichier[TAILLEMAX];

    printf("Nom du fichier de sauvegarde :");
    scanf("%s", nomFichier);
    strcat(nomFichier, ".txt");

    FILE *pFich = fopen(nomFichier, "w+");
    testerOuvertureFichier();
    int i, j;
    for(j = 0; j < nb; j++)
    {
        fprintf(pFich, "%d ", ad[j]->numCarte);
        fprintf(pFich, "%s ", ad[j]->nom);
        fprintf(pFich, "%s ", ad[j]->prenom);
        fprintf(pFich, "%d %d %d ", ad[j]->dateDeNaissance.jour, ad[j]->dateDeNaissance.mois, ad[j]->dateDeNaissance.annee);
        fprintf(pFich, "%d ", ad[j]->nbActivite);
        for(i = 0; i < ad[j]->nbActivite; i++)
        {
            switch (ad[j]->activite[i])
            {
            case NATATION:
                fprintf(pFich, "NATATION ");
                break;
            case BASKETBALL:
                fprintf(pFich, "BASKETBALL ");
                break;
            case HANDBALL:
                fprintf(pFich, "HANDBALL ");
                break;
            case SQUASH:
                fprintf(pFich, "SQUASH ");
                break;
            case TENNIS:
                fprintf(pFich, "TENNIS ");
                break;
            }
        }
        fprintf(pFich, "\n");
    }
    fclose(pFich);
}

int chargerAdherents(typeAdherent *ad[], int nb)
{
    int i;
    char nomFichier[TAILLEMAX];
    char tempoSport[TAILLEMAX];

    printf("Nom du fichier txt à ouvrir :");
    scanf("%s", nomFichier);

    strcat(nomFichier, ".txt");

    FILE *pFich = fopen(nomFichier, "r");
    testerOuvertureFichier();

    while(!feof(pFich))
    {
        nb++;
        ad[nb] = (typeAdherent*) malloc(sizeof(typeAdherent));
        fscanf(pFich, "%d %s %s %d %d %d %d", &ad[nb]->numCarte, ad[nb]->nom, ad[nb]->prenom, &ad[nb]->dateDeNaissance.jour,
                &ad[nb]->dateDeNaissance.mois, &ad[nb]->dateDeNaissance.annee, &ad[nb]->nbActivite);
        printf("%d\n", ad[nb]->nbActivite);
        for(i = 0; i < ad[nb]->nbActivite; i++)
        {
            fscanf(pFich, "%s", tempoSport);
            if(strcmp(tempoSport, "NATATION"))
            {
                ad[nb]->activite[i] = NATATION;
            }
            else
            {
                if(strcmp(tempoSport, "BASKETBALL"))
                {
                    ad[nb]->activite[i] = BASKETBALL;
                }
                else
                {
                    if(strcmp(tempoSport, "HANDBALL"))
                    {
                        ad[nb]->activite[i] = HANDBALL;
                    }
                    else
                    {
                        if(strcmp(tempoSport, "SQUASH"))
                        {
                            ad[nb]->activite[i] = SQUASH;
                        }
                        else{
                            if(strcmp(tempoSport, "TENNIS"))
                            {
                                ad[nb]->activite[i] = TENNIS;
                            }
                        }
                    }
                }
            }
        }
    }
    return nb;
}
