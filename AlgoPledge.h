#ifndef ALGOPLEDGE_H_INCLUDED
#define ALGOPLEDGE_H_INCLUDED

#include "Robot.h"

class AlgoPledge {
public:
    explicit AlgoPledge(Robot& robot);
    void executer();

private:
    Robot& robot;
};

#endif // ALGOPLEDGE_H_INCLUDED
