#include "AlgoPledge.h"
#include <iostream>

AlgoPledge::AlgoPledge(Robot& r) : robot(r) {}

void AlgoPledge::executer() {
    int compteur = 0;

    while (!robot.estArrive()) {
        if (!robot.devantMur()) {
            robot.avancer();
        } else {
            robot.tournerDroite();
            compteur--;
            if (!robot.devantMur()) {
                robot.avancer();
                compteur++;
            }
        }
        robot.obtenirTerrain().afficher(&robot); // Affiche le terrain avec le robot
    }
    std::cout << "Le robot a atteint la sortie avec l'algorithme de Pledge !\n";
}
