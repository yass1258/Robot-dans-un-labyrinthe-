#ifndef ALGOMAINDROITE_H_INCLUDED
#define ALGOMAINDROITE_H_INCLUDED

#include "Robot.h"

class AlgoMainDroite {
public:
    explicit AlgoMainDroite(Robot& robot);
    int calculerDistance(const Position& pos1, const Position& pos2) const;
    void executer();

private:
    Robot& robot;
};

#endif // ALGOMAINDROITE_H_INCLUDED
