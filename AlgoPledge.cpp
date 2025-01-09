#include "AlgoPledge.h"
#include <iostream>
#include "Robot.h"
#include "Deplacement.h"
#include "Capteur.h"


AlgoPledge::AlgoPledge(Robot& r) : robot(r), compteurOrientation(0) {}

void AlgoPledge::executer() {
Deplacement deplacement(robot); // Utilisation de la classe Deplacement

    while (!robot.estArrive()) { // Continue tant que le robot n'a pas atteint la sortie
        std::cout << "Position actuelle : (" << robot.obtenirPosition().getX() << ", "
                  << robot.obtenirPosition().getY() << "), Direction : " << robot.getDirection()
                  << ", Compteur : " << compteurOrientation << "\n";

        // Si la case devant est l'arriv�e, le robot s'arr�te
        if (robot.caseDevant() == 'A') {
            std::cout << "Le robot est juste avant la case d'arriv�e. Arr�t.\n";
            break; // Sortir de la boucle
        }

        if (compteurOrientation == 0 && !deplacement.devantMur()) {
            std::cout << "Avancer tout droit.\n";
            deplacement.avancer();
        } else {
            // Sinon, suivre le mur
            if (!robot.aDroiteMur()) {
                std::cout << "Tourner � droite.\n";
                deplacement.tournerDroite();
                compteurOrientation--;
            } else if (!deplacement.devantMur()) {
                std::cout << "Avancer en suivant le mur.\n";
                deplacement.avancer();
            } else {
                std::cout << "Tourner � gauche.\n";
                deplacement.tournerGauche();
                compteurOrientation++;
            }
        }

        // Affiche la grille apr�s chaque mouvement
        robot.obtenirTerrain().afficher(&robot);
    }

    std::cout << "Le robot a atteint la sortie avec l'algorithme de Pledge !\n";
}
