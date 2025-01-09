#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "Robot.h"

class Capteur {
public:
    explicit Capteur(Robot& robot);

    // Méthodes de détection
    bool devantMur() const;
    bool aDroiteMur() const;
    bool aGaucheMur() const;

    // Méthode pour détecter la case devant
    char caseDevant() const;

private:
    Robot& d_robot; // Référence au robot
};

#endif // CAPTEUR_H
