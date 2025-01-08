#include "AfficheurRobot.h"
#include "Robot.h"

void AfficheurRobot::notifier(const Robot& robot) {
    std::cout << "Le robot est maintenant en ("
              << robot.obtenirPosition().getX() << ", "
              << robot.obtenirPosition().getY() << ")." << std::endl;
}
