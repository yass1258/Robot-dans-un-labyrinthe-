#include "AlgoMainDroite.h"
#include <iostream>

AlgoMainDroite::AlgoMainDroite(Robot& robot) : robot(robot) {}

void AlgoMainDroite::executer() {
    // Tant que le robot n'est pas arriv� � la sortie
    while (!robot.estArrive()) {
        // Appliquer l'algorithme de la main droite
        if (!robot.aDroiteMur()) {
            robot.tournerDroite();
            robot.avancer();
        } else if (!robot.devantMur()) {
            robot.avancer();
        } else {
            robot.tournerGauche();
        }

        // Afficher le terrain apr�s chaque mouvement
        robot.obtenirTerrain().afficher();
        std::cout << "Position actuelle : (" << robot.obtenirPosition().getX()
                  << ", " << robot.obtenirPosition().getY() << ") Direction : "
                  << robot.getDirection() << "\n";
        if (robot.caseDevant() == 'A') {
            std::cout << "Le robot est juste avant la case d'arriv�e. Arr�t.\n";
            break; // Sortir de la boucle
        }
    }




}
