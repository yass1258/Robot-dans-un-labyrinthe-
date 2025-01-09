#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "Robot.h"

class Capteur {
public:
    explicit Capteur(Robot& robot);

    // M�thodes de d�tection
    bool devantMur() const;
    bool aDroiteMur() const;
    bool aGaucheMur() const;

    // M�thode pour d�tecter la case devant
    char caseDevant() const;

private:
    Robot& d_robot; // R�f�rence au robot
};

#endif // CAPTEUR_H
