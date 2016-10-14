#ifndef REVEIL_H_INCLUDED
#define REVEIL_H_INCLUDED

#include "horloge.h"

enum MODES_ALARME
{
    ACTIVER_ALARME = 3,
    REGLAGE_HEURES_ALARME,
    REGLAGE_MINUTES_ALARME
};

class Reveil : private Horloge
{
private:
    short heureAlarme;
    short minuteAlarme;
    bool active;

    Horloge *monHorloge = new Horloge();

public:
    Reveil(const short _resolution=24, const short _nbMode=6);
    ~Reveil();
    bool Surveiller();
    void AvancerHeureAlarme();
    void ReculerHeureALarme();
    void AvancerMinuteAlarme();
    void ReculerMinuteAlarme();
    void Controler();
    void ChangerEtatAlarme();
};
#endif // REVEIL_H_INCLUDED
