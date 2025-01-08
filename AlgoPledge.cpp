#include "AlgoPledge.h"
#include <iostream>
#include "Robot.h"
AlgoPledge::AlgoPledge(Robot& r) : robot(r), compteurOrientation(0) {}


    void AlgoPledge::executer() {
    while (!robot.estArrive()) { // Continue tant que le robot n'a pas atteint la sortie
        std::cout << "Position actuelle : (" << robot.obtenirPosition().getX() << ", " << robot.obtenirPosition().getY()
                  << "), Direction : " << robot.getDirection() << ", Compteur : " << compteurOrientation << "\n";

        // Si la case devant est l'arrivée, le robot s'arrête
        if (robot.caseDevant() == 'A') {
            std::cout << "Le robot est juste avant la case d'arrivée. Arrêt.\n";
            break; // Sortir de la boucle
        }

        if (compteurOrientation == 0 && !robot.devantMur()) {
            std::cout << "Avancer tout droit.\n";
            robot.avancer();
        } else {
            // Sinon, suivre le mur
            if (!robot.aDroiteMur()) {
                std::cout << "Tourner à droite.\n";
                robot.tournerDroite();
                compteurOrientation--;
            } else if (!robot.devantMur()) {
                std::cout << "Avancer en suivant le mur.\n";
                robot.avancer();
            } else {
                std::cout << "Tourner à gauche.\n";
                robot.tournerGauche();
                compteurOrientation++;
            }
        }

        // Affiche la grille après chaque mouvement
        robot.obtenirTerrain().afficher(&robot);
    }

    std::cout << "Le robot a atteint la sortie avec l'algorithme de Pledge !\n";
    }
