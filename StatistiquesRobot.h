#ifndef STATISTIQUESROBOT_H_INCLUDED
#define STATISTIQUESROBOT_H_INCLUDED

#include "ObservateurRobot.h"

class StatistiquesRobot : public ObservateurRobot {
private:
    int deplacements;

public:
    StatistiquesRobot();
    void notifier(const Robot& robot) override;
    int obtenirDeplacements() const;
};

#endif // STATISTIQUESROBOT_H_INCLUDED
