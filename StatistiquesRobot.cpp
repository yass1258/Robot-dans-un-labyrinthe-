#include "StatistiquesRobot.h"
#include "Robot.h"

StatistiquesRobot::StatistiquesRobot() : deplacements(0) {}

void StatistiquesRobot::notifier(const Robot& robot) {
    deplacements++;
}

int StatistiquesRobot::obtenirDeplacements() const {
    return deplacements;
}
