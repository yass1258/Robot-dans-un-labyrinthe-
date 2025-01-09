#include "AlgoMainDroite.h"
#include "Deplacement.h"
#include <iostream>
#include "Capteur.h"

AlgoMainDroite::AlgoMainDroite(Robot& robot) : robot(robot) {}

void AlgoMainDroite::executer() {
    Deplacement deplacement(robot);
    Capteur capteur(robot);
    while (!robot.estArrive()) {
        if (capteur.caseDevant() == 'A') {
            deplacement.avancer();
            std::cout << "Le robot est arrivé à la sortie avec l'algorithme de la main droite !\n";
            return;
        }

        if (!capteur.devantMur()) {
            deplacement.avancer();
        } else if (!capteur.aDroiteMur()) {
            deplacement.tournerDroite();
            deplacement.avancer();
        } else {
            deplacement.tournerGauche();
        }

        robot.obtenirTerrain().afficher(&robot);
        std::cout << "Position actuelle : (" << robot.obtenirPosition().getX() << ", "
              << robot.obtenirPosition().getY() << ") Direction : "
              << obtenirDirectionTexte(robot.getDirection()) << "\n";
    }

}

