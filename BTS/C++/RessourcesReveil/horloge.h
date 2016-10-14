#ifndef HORLOGE_H
#define HORLOGE_H

#include "clavier.h"
#include "cadran.h"
#include <time.h>

enum MODE_HORLOGE
{
    AUCUN_REGLAGE,
    REGLAGE_HEURES,
    REGLAGE_MINUTES,
    REGLAGE_ALARME
};

class Horloge
{
    public:
        Horloge(const short _nbMode = 3, const short _resolution = 24 );
        void ActualiserHeure();
        bool AvancerHeures();
        bool AvancerMinutes();
        void ReculerHeures();
        void ReculerMinutes();
        TOUCHES_CLAVIER Controler(const TOUCHES_CLAVIER numTouche);
        void ChangerMode();
    private:
        short heures;
        short minutes;
        short resolution;
        const short nbMode;
        short mode;
        time_t valAvant ;

        Clavier leClavier;
        Cadran  leCadran;
};

#endif // HORLOGE_H
