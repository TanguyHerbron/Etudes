#include "horloge.h"
#include "clavier.h"

Horloge::Horloge(const short _nbMode, const short _resolution ) :
   heures(0),minutes(0),  resolution(_resolution),nbMode(_nbMode),mode (AUCUN_REGLAGE)
{
    valAvant = time(NULL);
}

bool Horloge::AvancerHeures()
{
    bool retour = false;
    if(++heures == resolution)
    {
        heures = 0;
        retour = true;
    }
    return retour;
}

bool Horloge::AvancerMinutes()
{
    bool retour = false;
    if(++minutes == 60)
    {
        minutes = 0;
        retour = true;
    }
    return retour;
}

void Horloge::ReculerHeures()
{
    if(--heures == -1)
        heures = resolution -1;
}

void Horloge::ReculerMinutes()
{
    if(--minutes == -1)
        minutes = 59 ;
}

void Horloge::ActualiserHeure()
{
    time_t valCourante = time(NULL);
    double seconde = difftime(valCourante,valAvant);

    if(seconde>60) // à modifier pour aller plus vite pendant le test
    {
        valAvant = valCourante ;
        if(AvancerMinutes())
            AvancerHeures();
    }
}

TOUCHES_CLAVIER Horloge::Controler(const TOUCHES_CLAVIER numTouche)
{

    switch(mode)
    {
        case AUCUN_REGLAGE :
             leCadran.Afficher(heures,1);
             leCadran.Afficher(minutes,4);
             if(numTouche == MODE)
                ChangerMode();
             else ActualiserHeure();
             break;

        case REGLAGE_HEURES:
             switch(numTouche)
             {
                case PLUS:
                     AvancerHeures();
                     break;
                case MOINS:
                     ReculerHeures();
                     break;
                case MODE:
                     ChangerMode();
                     break;
                default:
                    break;
             }
             if(mode != AUCUN_REGLAGE)
             {
                leCadran.Afficher("HH",1);
                leCadran.Afficher(heures,4);
             }
             break;
        case REGLAGE_MINUTES:
             switch(numTouche)
             {
                case PLUS:
                     AvancerMinutes();
                     break;
                case MOINS:
                     ReculerMinutes();
                     break;
                case MODE:
                     ChangerMode();
                     break;
                default:
                     break;
             }
             if(mode != AUCUN_REGLAGE)
             {
                leCadran.Afficher("MM",1);
                leCadran.Afficher(minutes,4);
             }
             break;
    }
    return leClavier.ScruterClavier() ;
}

void Horloge::ChangerMode()
{
     leCadran.Afficher("         ");
     mode = (mode+1)%nbMode;
}
