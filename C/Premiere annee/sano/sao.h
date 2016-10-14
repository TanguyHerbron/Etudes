#ifndef SAO_H_INCLUDED
#define SAO_H_INCLUDED

#define NBMAXCARNOM 50
#define NBMAXCARPRENOM 50
#define EXPERIENCEPASSAGE 200
#define PVMAXINIT 500

#define RESBRETTEUR 20
#define RESPALADIN 15
#define RESBERSERK 5
#define RESASSASSIN 25
#define RESGUERRIER 10
#define RESSAMOURAI 15

#define BONUSDEFPALA 1.5
#define BONUSDEFSAM 1.5
#define BONUSDEFBER 0.5
#define BONUSDEFBRE 1.5
#define BONUSDEFGUE 1
#define BONUSDEFASS 3

#define BONUSATTPALA 1.5
#define BONUSATTSAM 1.5
#define BONUSATTBER 3
#define BONUSATTBRE 1.75
#define BONUSATTGUE 1
#define BONUSATTASS 0.5

typedef enum
{
    FALSE=0, TRUE
}booleen;

/*definition du type enum competenceDeClasse*/

typedef enum
{
    BRETTEUR=1, PALADIN, BERSERK, ASSASSIN, GUERRIER, SAMOURAI
} competenceDeClasse;

typedef enum
{
    BOUCLIER=-10, RIEN=0, DAGUE=5,WAKIZASHI=8,GLAIVE=10, XIPHOS=11, CLADIO=12, RAPIERE=13

} armesUneMain;

typedef enum
{
    NIL=0, BATARDE=25, KATANA=30, CLAYMORE=32,  FLAMBERGE=35
} armesDeuxMains;

/*definition du type structure typeArmement*/

typedef struct
{
    armesUneMain mainGauche;
    armesUneMain mainDroite;
    armesDeuxMains deuxMains;
}typeArmement;

typedef struct
{
    char nom[NBMAXCARNOM];
    char prenom[NBMAXCARPRENOM];
    unsigned int age;
    float taille;
    float poids;
    int resistancePhysique;
    int pv;
    unsigned int pvMax;
    unsigned int niveau;
    unsigned int experience;
    competenceDeClasse competence;
    typeArmement armes;
} typePersonnage;

void msleep(unsigned int maxTime);
unsigned int aleatoire(unsigned int maxAlea );

int calculAttaque(typePersonnage *att);
int calculDefense(typePersonnage *def);
void mettreAJourNiveau(typePersonnage *perso, unsigned int exp);
unsigned int calculerGainExperience(typePersonnage *p1,typePersonnage *p2, booleen victoire,unsigned int tours);
void afficherClasse(competenceDeClasse c);
void afficherArmeDeuxMains(armesDeuxMains adm);
void afficherArmement(typeArmement arm);
armesUneMain choisirArmeUneMain();
armesDeuxMains choisirArmeDeuxMains();
unsigned int determinerResistance(competenceDeClasse classe);
typePersonnage* creerPersonnage();
void faireUnDuel(typePersonnage *j1,typePersonnage *j2);

/*déclaration des fonctions à faire*/

void afficherPersonnage(typePersonnage *joueur);
void afficherMenu(typePersonnage *joueur1, typePersonnage *joueur2);
typePersonnage* chargerPersonnage();
void sauvegarderPersonnages(typePersonnage *joueur);
int calculDegats(typePersonnage *attaquant, typePersonnage *defenseur);

#endif // SAO_H_INCLUDED

