#include "AlgoMainDroite.h"
#include <iostream>

AlgoMainDroite::AlgoMainDroite(Robot& r) : robot(r) {}

void AlgoMainDroite::executer() {
    while (!robot.estArrive()) {
        if (!robot.aDroiteMur()) {
            robot.tournerDroite();
            robot.avancer();
        } else if (!robot.devantMur()) {
            robot.avancer();
        } else {
            robot.tournerGauche();
        }
        robot.obtenirTerrain().afficher(&robot); // Affiche le terrain avec le robot
    }
    std::cout << "Le robot a atteint la sortie avec l'algorithme de la main droite !\n";
}
