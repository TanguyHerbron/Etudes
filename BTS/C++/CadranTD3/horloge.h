#ifndef HORLOGE_H_INCLUDED
#define HORLOGE_H_INCLUDED

#include <ncurses.h>	// pour les fonctions d'affichage
#include <unistd.h> 	// pour sleep
#include "cadran.h"
#include "clavier.h"

enum MODES_HORLOGE
{

    AUCUN_REGLAGE = 0,
    REGLAGE_HEURES,
    REGLAGE_MINUTES
};

class Horloge
{
protected:
    short heures;
    short minutes;
    const short resolution;
    short mode;
    const short nbMode;

    Cadran *leCadran = new Cadran();
    Clavier *leClavier = new Clavier();

public:
    Horloge(const short _resolution=24, const short _nbMode=3);
    ~Horloge();
    bool ActualiserHeure();
    bool AvancerHeures();
    bool AvancerMinutes();
    void ReculerHeures();
    void ReculerMinutes();
    void Controler();
    void ChangerMode();
};

#endif // HORLOGE_H_INCLUDED
