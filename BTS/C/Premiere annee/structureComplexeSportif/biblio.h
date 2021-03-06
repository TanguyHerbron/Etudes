#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#define NBSPORT 5
#define TAILLEMAX 50

typedef enum{
    NATATION,
    BASKETBALL,
    HANDBALL,
    SQUASH,
    TENNIS
}sport;

typedef struct{
    int jour;
    int mois;
    int annee;
}date;

typedef struct{
    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    date dateDeNaissance;
    int nbActivite;
    sport activite[NBSPORT];
    int numCarte;
}typeAdherent;

void effacerEcran();

void afficherMenu(int compteurAdherent);

void afficherDate(date dateAfficher);

void afficherActivite(sport listSport);

typeAdherent *creerUnAdherent();

void afficherUnAdherent(typeAdherent *adherent[], int numeroCarte, int nb);

void afficherAdherents(typeAdherent *ad[], int nb);

int ajouterUnAdherent(typeAdherent *tab[], int nb);

int supprimerUnAdherent(typeAdherent *tab[], int nro, int nb);

int supprimerAdherents(typeAdherent *tab[], int nb);

void modifierFiche(typeAdherent *tab[], int nro, int nb);

int chargerAdherents(typeAdherent *ad[], int nb);

#endif // BIBLIO_H_INCLUDED
