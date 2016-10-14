#include <stdio.h>
#include "horloge.h"

Horloge::Horloge(const short _resolution, const short _nbMode)
    : heures(0), minutes(0), resolution(_resolution), mode(AUCUN_REGLAGE), nbMode(_nbMode)
{}

Horloge::~Horloge()
{

}

bool Horloge::ActualiserHeure()
{
    bool retour = false;
    bool changementHeure;

    changementHeure = AvancerMinutes();

    if(changementHeure)
    {
        retour = AvancerHeures();
    }

    leCadran->Afficher(heures, 1);
    leCadran->Afficher(minutes, 5);

    return retour;
}

bool Horloge::AvancerHeures()
{
    bool retour = false;

    heures++;

    if(heures == 12 && resolution == 12)
    {
        heures = 0;
        retour = true;
    }

    if(heures == 24)
    {
        heures = 0;
        retour = true;
    }

    return retour;
}

bool Horloge::AvancerMinutes()
{
    bool retour = false;

    minutes++;
    if(minutes == 60)
    {
        minutes = 0;
        retour = true;
    }

    return retour;
}

void Horloge::ReculerHeures()
{
    heures--;
    if(heures < 0)
    {
        heures = 23;
    }
}

void Horloge::ReculerMinutes()
{
    minutes--;
    if(minutes < 0)
    {
        minutes = 59;
        ReculerHeures();
    }
}

void Horloge::Controler()
{

    short numTouche;
    int tempo = 0;

    numTouche = leClavier->ScruterClavier();

    switch(mode)
    {
    case AUCUN_REGLAGE:

        tempo++;

        if(tempo == 10000)
        {
            ActualiserHeure();
            tempo = 0;
        }

        if(numTouche == MODE)
        {
            ChangerMode();
        }

        break;

    case REGLAGE_HEURES:

        leCadran->Afficher("HH", 1);
        leCadran->Afficher(heures, 5);
        switch(numTouche)
        {
        case PLUS:
            AvancerHeures();
            leCadran->Afficher(heures, 5);
            break;

        case MOINS:
            ReculerHeures();
            leCadran->Afficher(heures, 5);
            break;

        case MODE:
            ChangerMode();
        }

        break;

    case REGLAGE_MINUTES:

        leCadran->Afficher("MM", 1);
        leCadran->Afficher(minutes, 5);
        switch(numTouche)
        {
        case PLUS:
            AvancerMinutes();
            leCadran->Afficher(minutes, 5);
            break;

        case MOINS:
            ReculerMinutes();
            leCadran->Afficher(minutes, 5);
            break;

        case MODE:
            ChangerMode();
        }

        break;
    }

    usleep(99);

}

void Horloge::ChangerMode()
{
    mode = (mode+1)%nbMode;
}
