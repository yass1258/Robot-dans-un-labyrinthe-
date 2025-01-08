#ifndef ALGOPLEDGE_H_INCLUDED
#define ALGOPLEDGE_H_INCLUDED

#include "Robot.h"

class AlgoPledge {
public:
    explicit AlgoPledge(Robot& r);
    void executer(); // Exécute l'algorithme de Pledge
private:
    Robot& robot;
    int compteurOrientation; // Compteur d'orientation
};

#endif // ALGOPLEDGE_H_INCLUDED
