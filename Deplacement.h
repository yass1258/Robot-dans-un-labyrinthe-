#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include "Robot.h"
#include "Constantes.h"

class Deplacement {
public:
    Deplacement(Robot& robot);

    void avancer();
    void tournerDroite();
    void tournerGauche();
    bool devantMur() const;
    char caseDevant() const;

private:
    Robot& robot;
};

#endif
