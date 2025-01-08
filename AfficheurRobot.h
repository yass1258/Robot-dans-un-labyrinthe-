#ifndef AFFICHEURROBOT_H_INCLUDED
#define AFFICHEURROBOT_H_INCLUDED

#include "ObservateurRobot.h"
#include <iostream>

class AfficheurRobot : public ObservateurRobot {
public:
    void notifier(const Robot& robot) override;
};

#endif // AFFICHEURROBOT_H_INCLUDED
