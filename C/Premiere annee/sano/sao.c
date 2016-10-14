/*********************************************************************
Nom du projet : sao
Nom du fichier : sao.c
Auteur : dbernard
Date de création : Friday 2015-12-04-13.57
------------------------------------------
Edition : therbron
Date d'edition : Thursday 2015-12-10-13.28
------------------------------------------
Copyright 2013 par depinfo.touchard
Description fonctionnelle de la bibliotheque :



*********************************************************************/

#include "sao.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/timeb.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

// attendre un maxTime millisecondes
void msleep(unsigned int maxTime)
{
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
    };
    */
    struct timespec req;
    struct timespec rem;
    time_t secondes=0;
    long nanoSecondes=0;
    if (maxTime>=1000)
    {
        do
        {
            secondes++;
            maxTime-=1000;
        }
        while(maxTime>=1000);
    }
    nanoSecondes=maxTime*1000000;
    req.tv_sec=secondes;
    req.tv_nsec=nanoSecondes;
    nanosleep(&req,&rem);

}

//retourne une valeur entiere E[0..maxAlea[
unsigned int aleatoire(unsigned int maxAlea )
{
    /* struct timeb {
        time_t         time;
        unsigned short millitm;
        short          timezone;
        short          dstflag;
    };*/

    struct timeb t;
    float a, b ;
    unsigned int nbmilli;
    ftime( &t );
    nbmilli = t.time * 1000 + t.millitm;
    srand( nbmilli );
    a = rand();
    b = ( maxAlea * a ) / RAND_MAX;
    msleep(50);
    return( ( unsigned int )b );


}


void afficherMenu(typePersonnage *joueur1, typePersonnage *joueur2)
{
    if(joueur1 == NULL)
    {
        printf("1 - Creer personnage joueur 1\n");
        printf("2 - Charger joueur 1\n");
    }

    if(joueur2 == NULL)
    {
        printf("3 - Creer personnage joueur 2\n");
        printf("4 - Charger joueur 2\n");
    }

    if((joueur1 != NULL) && (joueur2 != NULL))
    {
        printf("5 - joueur 1 vs joueur 2\n");
        printf("6 - joueur 1 vs joueur 2 X10\n");
        printf("7 - joueur 2 vs joueur 1\n");
        printf("8 - joueur 2 vs joueur 1 X 10\n");
        printf("9 - Afficher joueur 1\n");
        printf("10 - Afficher joueur 2\n");
        printf("11 - Sauvegarder joueur 1\n");
        printf("12 - Sauvegarder joueur 2\n");
    }

    printf("13 - Quitter\n");
}


int calculAttaque(typePersonnage *att)
{
    double bonus;
    double attaque;
    switch (att->competence)
    {
    case PALADIN:
        bonus=BONUSATTPALA;
        break;
    case SAMOURAI:
        bonus=BONUSATTSAM;
        break;
    case BERSERK:
        bonus=BONUSATTBER;
        break;
    case BRETTEUR:
        bonus=BONUSATTBRE;
        break;
    case GUERRIER:
        bonus=BONUSATTGUE;
        break;
    case ASSASSIN:
        bonus=BONUSATTASS;
        break;
    }

    attaque=att->niveau*( (att->poids*att->taille)/ (double)att->age)*bonus;
    // je personnage possede une arme a 2 mains
    if (att->armes.deuxMains!=NIL)
    {
        attaque=attaque+att->armes.deuxMains;
    }
    else    // le personnage ne possede pas d'arme a 2 mains
    {
        // le perso n'a pas de bouclier
        if (att->armes.mainDroite!=BOUCLIER && att->armes.mainGauche!=BOUCLIER)
        {
            attaque=attaque+att->armes.mainDroite+att->armes.mainGauche;
        }
        else    // un bouclier dans l'une des mains
        {
            attaque=attaque+att->armes.mainDroite+att->armes.mainGauche-BOUCLIER+2;
        }
    }
    attaque=attaque*(0.5+aleatoire(10)/10.0);
    return (int)attaque;
}


int calculDefense(typePersonnage *def)
{
    double bonus;
    double defense;
    switch (def->competence)
    {
    case PALADIN:
        bonus=BONUSDEFPALA;
        break;
    case SAMOURAI:
        bonus=BONUSDEFSAM;
        break;
    case BERSERK:
        bonus=BONUSDEFBER;
        break;
    case BRETTEUR:
        bonus=BONUSDEFBRE;
        break;
    case GUERRIER:
        bonus=BONUSDEFGUE;
        break;
    case ASSASSIN:
        bonus=BONUSDEFASS;
        break;
    }

    defense=def->niveau*( (def->poids*def->taille)/ (double)def->age)*bonus;
    // je personnage possede une arme a 2 mains
    if (def->armes.deuxMains!=NIL)
    {
        defense=defense-(def->armes.deuxMains)/2;
    }
    else    // le personnage ne possede pas d'arme a 2 mains
    {
        // le perso n'a pas de bouclier
        if (def->armes.mainDroite!=BOUCLIER && def->armes.mainGauche!=BOUCLIER)
        {
            defense=defense-(def->armes.mainDroite+def->armes.mainGauche)/3;
        }
        else    // un bouclier dans l'une des mains
        {
            defense=defense-BOUCLIER;
        }
    }
    defense=defense*(0.5+aleatoire(10)/10.0);
    return (int)defense;

}


void mettreAJourNiveau(typePersonnage *perso, unsigned int exp)
{
    perso->experience+=exp;
    if (perso->experience>=EXPERIENCEPASSAGE)
    {
        perso->niveau++;
        perso->experience-=EXPERIENCEPASSAGE;
        perso->pvMax+=PVMAXINIT/perso->niveau;
        perso->pv=perso->pvMax;
        switch (perso->competence)
        {
        case PALADIN:
            perso->resistancePhysique+=RESPALADIN;
            break;
        case SAMOURAI:
            perso->resistancePhysique+=RESSAMOURAI;
            break;
        case BERSERK:
            perso->resistancePhysique+=RESBERSERK;
            break;
        case BRETTEUR:
            perso->resistancePhysique+=RESBRETTEUR;
            break;
        case GUERRIER:
            perso->resistancePhysique+=RESGUERRIER;
            break;
        case ASSASSIN:
            perso->resistancePhysique+=RESASSASSIN;
            break;
        }
    }

}


unsigned int calculerGainExperience(typePersonnage *p1,typePersonnage *p2,booleen victoire,unsigned int tours)
{
    unsigned int exp=0;
    if (victoire)
    {
        exp=2*(p2->niveau-p1->niveau+1)*tours;

    }
    else
    {
        exp=(p2->niveau-p1->niveau+1)*tours;

    }
    return exp;

}


void afficherClasse(competenceDeClasse c)
{
    switch(c)
    {
    case PALADIN:
        printf("Paladin \n");
        break;
    case SAMOURAI:
        printf("Samourai\n");
        break;
    case BERSERK:
        printf("Berserk\n");
        break;
    case BRETTEUR:
        printf("Bretteur\n");
        break;
    case GUERRIER:
        printf("Guerrier\n");
        break;
    case ASSASSIN:
        printf("Assassin\n");
        break;
    }
}


void afficherArmeUneMain(armesUneMain aum)
{
    switch (aum)
    {
    case DAGUE:
        printf("Dague - degats : %d\n",DAGUE);
        break;
    case WAKIZASHI:
        printf("Wakizashi - degats : %d\n",WAKIZASHI);
        break;
    case GLAIVE:
        printf("Glaive - degats : %d\n",GLAIVE);
        break;
    case XIPHOS:
        printf("Xiphos - degats : %d\n",XIPHOS);
        break;
    case CLADIO:
        printf("Cladio - degats : %d\n",CLADIO);
        break;
    case RAPIERE:
        printf("Rapiere - degats : %d\n",RAPIERE);
        break;
    case BOUCLIER:
        printf("Bouclier - protection : %d\n",-BOUCLIER);
        break;
    case RIEN:
        printf("Vide - degats : 1\n");
        break;
    }
}

void afficherArmeDeuxMains(armesDeuxMains adm)
{
    switch (adm)
    {
    case NIL:
        printf("Nil - degats : %d\n",NIL);
        break;
    case BATARDE:
        printf("Batarde - degats : %d\n",BATARDE);
        break;
    case KATANA:
        printf("Katana - degats : %d\n",KATANA);
        break;
    case CLAYMORE:
        printf("Claymore - degats : %d\n",CLAYMORE);
        break;
    case FLAMBERGE:
        printf("Flamberge - degats : %d\n",FLAMBERGE);
        break;
    }
}

void afficherArmement(typeArmement arm)
{
    // il possede une arme a 2 mains
    if (arm.deuxMains!=NIL)
    {
        printf("2 mains : ");
        afficherArmeDeuxMains(arm.deuxMains);
    }
    else
    {
        printf("Main gauche : ");
        afficherArmeUneMain(arm.mainGauche);
        printf("Main droite : ");
        afficherArmeUneMain(arm.mainDroite);
    }
}


void afficherPersonnage(typePersonnage *perso)
{
    printf("Classe  : ");
    afficherClasse(perso->competence);
    printf("Nom: %s\nPrenom : %s\nAge : %d\nTaille : %.2f\nPoids : %.2f\n",perso->nom,perso->prenom,perso->age,perso->taille,perso->poids);
    printf("Resistance : %d\nPoints de vie : [%d/%d]\n",perso->resistancePhysique,perso->pv,perso->pvMax);
    printf("Niveau : %d\nExperience dans le niveau : %d/%d\n",perso->niveau,perso->experience,EXPERIENCEPASSAGE);
    afficherArmement(perso->armes);
}


armesUneMain choisirArmeUneMain()
{
    armesUneMain arme;
    int choix;
    do
    {
        printf("Choix de l'arme :\n");
        printf(" 1 :");
        afficherArmeUneMain(DAGUE);
        printf(" 2 :");
        afficherArmeUneMain(WAKIZASHI);
        printf(" 3 :");
        afficherArmeUneMain(GLAIVE);
        printf(" 4 :");
        afficherArmeUneMain(XIPHOS);
        printf(" 5 :");
        afficherArmeUneMain(CLADIO);
        printf(" 6 :");
        afficherArmeUneMain(RAPIERE);
        printf("\n votre choix : ");
        scanf("%d",&choix);
    }
    while(choix<1 || choix >6);
    switch(choix)
    {
    case 1:
        arme=DAGUE;
        break;
    case 2:
        arme=WAKIZASHI;
        break;
    case 3:
        arme=GLAIVE;
        break;
    case 4:
        arme=XIPHOS;
        break;
    case 5:
        arme=CLADIO;
        break;
    case 6:
        arme=RAPIERE;
        break;
    }
    return arme;

}


armesDeuxMains choisirArmeDeuxMains()
{
    armesDeuxMains arme;
    int choix;
    do
    {
        printf("Choix de l'arme : \n");
        printf(" 1 :");
        afficherArmeDeuxMains(BATARDE);
        printf(" 2 :");
        afficherArmeDeuxMains(KATANA);
        printf(" 3 :");
        afficherArmeDeuxMains(CLAYMORE);
        printf(" 4 :");
        afficherArmeDeuxMains(FLAMBERGE);
        printf("\n votre choix : ");
        scanf("%d",&choix);
    }
    while(choix<1 || choix >4);
    switch(choix)
    {
    case 1:
        arme=BATARDE;
        break;
    case 2:
        arme=KATANA;
        break;
    case 3:
        arme=CLAYMORE;
        break;
    case 4:
        arme=FLAMBERGE;
        break;
    }
    return arme;

}


unsigned int determinerResistance(competenceDeClasse c)
{
    unsigned int res;

    switch(c)
    {
    case PALADIN:
        res=RESPALADIN;
        break;
    case SAMOURAI:
        res=RESSAMOURAI;
        break;
    case BERSERK:
        res=RESBERSERK;
        break;
    case BRETTEUR:
        res=RESBRETTEUR;
        break;
    case GUERRIER:
        res=RESGUERRIER;
        break;
    case ASSASSIN:
        res=RESASSASSIN;
        break;
    }
    return res;
}


typePersonnage* creerPersonnage()
{
    typePersonnage* p=malloc(sizeof(typePersonnage));
    int choix;
    char unOuDeux;
    do
    {
        printf("choix de la classe :\n");
        printf(" 1 - Bretteur\n");
        printf(" 2 - Paladin\n");
        printf(" 3 - Berserk\n");
        printf(" 4 - Assassin\n");
        printf(" 5 - Guerrier\n");
        printf(" 6 - Samourai\n");
        printf("Votre choix : ");
        scanf("%d",&choix);
    }
    while(choix<1 || choix >6);

    switch (choix)
    {
    case 1:
        p->competence=BRETTEUR;
        break;
    case 2:
        p->competence=PALADIN;
        break;
    case 3:
        p->competence=BERSERK;
        break;
    case 4:
        p->competence=ASSASSIN;
        break;
    case 5:
        p->competence=GUERRIER;
        break;
    case 6:
        p->competence=SAMOURAI;
        break;
    }
    printf("Nom :");
    scanf(" %s",p->nom);
    printf("Prenom :");
    scanf(" %s",p->prenom);
    printf("Age :");
    scanf("%d",&p->age);
    printf("Taille :");
    scanf("%f",&p->taille);
    printf("Poids :");
    scanf("%f",&p->poids);


    p->pv=PVMAXINIT;
    p->pvMax=PVMAXINIT;
    p->experience=0;
    p->niveau=1;

    p->resistancePhysique=determinerResistance(p->competence);
    // si berserk ne peut avoir qu'une arme a 2 mains
    if (p->competence==BERSERK)
    {

        p->armes.deuxMains=choisirArmeDeuxMains();
    }
    else    // pas berserk
    {
        p->armes.deuxMains=NIL;
        if (p->competence==PALADIN ||  p->competence==SAMOURAI)
        {
            do
            {
                printf("Voulez vous utiliser une arme à deux mains(o/n)?");
                scanf(" %c",&unOuDeux);

            }
            while(unOuDeux!='o' && unOuDeux!='n' );
            if (unOuDeux=='o')
            {
                p->armes.deuxMains=choisirArmeDeuxMains();

            }
            else
            {
                p->armes.mainDroite=choisirArmeUneMain();

                if (p->competence==PALADIN) // epee et bouclier
                {

                    p->armes.mainGauche=BOUCLIER;

                }
                if (p->competence==SAMOURAI) // epee et main libre
                {

                    p->armes.mainGauche=RIEN;

                }

            }
        }
        if (p->competence==ASSASSIN)
        {
            p->armes.mainDroite=choisirArmeUneMain();
            p->armes.mainGauche=RIEN;

        }
        if (p->competence==BRETTEUR)
        {
            do
            {
                printf("Voulez vous utiliser deux armes (o/n)?");
                scanf(" %c",&unOuDeux);

            }
            while(unOuDeux!='o' && unOuDeux!='n' );
            if (unOuDeux=='o')
            {
                printf("Main droite : ");
                p->armes.mainDroite=choisirArmeUneMain();
                printf("Main gauche : ");
                p->armes.mainGauche=choisirArmeUneMain();
            }
            else
            {
                p->armes.mainDroite=choisirArmeUneMain();

                p->armes.mainGauche=RIEN;

            }

        }
        if (p->competence==GUERRIER)
        {
            do
            {
                printf("Voulez vous utiliser un bouclier(o/n)?");
                scanf(" %c",&unOuDeux);

            }
            while(unOuDeux!='o' && unOuDeux!='n' );
            if (unOuDeux=='o')
            {
                printf("Main droite : ");
                p->armes.mainDroite=choisirArmeUneMain();

                p->armes.mainGauche=BOUCLIER;
            }
            else
            {
                p->armes.mainDroite=choisirArmeUneMain();

                p->armes.mainGauche=RIEN;

            }

        }

    }

    return p;
}


void faireUnDuel(typePersonnage *j1,typePersonnage *j2)
{
    booleen j1gagne=FALSE;
    booleen j2gagne=FALSE;
    int tour=0;
    int expj1,expj2;
    int degatJ1vsJ2;
    int degatJ2vsJ1;

    do
    {
        degatJ1vsJ2=calculDegats(j1,j2);
// mettre a jour les pv de j2 (pv actuel - degat)

        j2->pv = j2->pv - degatJ1vsJ2;

// afficher j1 attaque j2 et degats occasionnes

        printf("Le joueur 1 attaque le joueur 2 et lui inflige %d de degats.\n", degatJ1vsJ2);

        degatJ2vsJ1=calculDegats(j2,j1);
// mettre a jour les pv de j1 (pv actuel - degat)

        j1->pv = j1->pv - degatJ2vsJ1;

// afficher j1 attaque j2 et degats occasionnes

        printf("Le joueur 2 attaque le joueur 1 et lui inflige %d de degats.\n", degatJ2vsJ1);

// afficher les pv des deux joueurs

        printf("%s [%d/%d]pv\n", j1->nom, j1->pv, j1->pvMax);
        printf("%s [%d/%d]pv\n", j2->nom, j2->pv, j1->pvMax);

// augmenter le nombre de tours

        tour++;
    }
    while (j1->pv>0 && j2->pv>0);

    if (j1->pv>0)
    {
        j1gagne=TRUE;
// remettre les pv de j2 au maximum

        j2->pv = j2->pvMax;

    }
    else
    {
        j2gagne=TRUE;
// remettre les pv de j1 au maximum

        j1->pv = j1->pvMax;

    }

    expj1 = calculerGainExperience(j1,j2,j1gagne,tour);
// mettre a jour j1

    mettreAJourNiveau(j1, expj1);

    expj2 = calculerGainExperience(j2,j1,j2gagne,tour);
// mettre a jour j2

    mettreAJourNiveau(j2, expj2);

// afficher j1

    printf("++++++++++++++++++++++++++++++++");

    afficherPersonnage(j1);

    printf("=================================");
// afficher j2

    afficherPersonnage(j2);

    printf("++++++++++++++++++++++++++++++++");

}


int calculDegats(typePersonnage *attaquant, typePersonnage *defenseur)
{
    float degats;

    degats = calculAttaque(attaquant) - calculDefense(defenseur);

    if(degats <= 0){
        degats = 1;
    }

    return degats;
}


void sauvegarderPersonnages(typePersonnage *joueur)
{
    char nomFichier[NBMAXCARNOM];

    printf("Nom du fichier txt de sauvegarde :");
    scanf("%s", nomFichier);

    FILE *pFich = fopen(nomFichier, "w+");

    //Test si le fichier est correcte
    if(pFich == -1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    fwrite(joueur, sizeof(typePersonnage), 1, pFich);

    fclose(pFich);
}


typePersonnage* chargerPersonnage()
{
    char nomFichier[NBMAXCARNOM];
    typePersonnage* joueur=malloc(sizeof(typePersonnage));

    printf("Nom du fichier txt à ouvrir \n(le fichier en question doit etre a la racine du programme):");
    scanf("%s", nomFichier);

    FILE *pFich = fopen(nomFichier, "r");

    //Test si le fichier est correcte
    if(pFich == -1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    fread(joueur, sizeof(typePersonnage), 1, pFich);

    fclose(pFich);

    return joueur;
}
