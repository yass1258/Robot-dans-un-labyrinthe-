#include <iostream>
#include "Terrain.h"
#include "Robot.h"
#include "AlgoMainDroite.h"
#include "AlgoPledge.h"

int main() {
    Terrain terrain;

    // Créer un terrain simple 5x5
    terrain.creer(5, 5);

    // Ajouter des murs
    terrain.placerMur(1, 1);
    terrain.placerMur(1, 2);
    terrain.placerMur(2, 2);

    // Définir les cases départ et arrivée
    terrain.definirDepart(0, 0);
    terrain.definirArrivee(4, 4);

    // Afficher le terrain initial
    std::cout << "Terrain initial :\n";
    terrain.afficher(nullptr); // Affiche le terrain sans robot

    // Créer un robot
    Robot robot(terrain);
    robot.sePositionner(0, 0, DROITE);

    // Demander à l'utilisateur de choisir un algorithme
    std::cout << "Choisissez un algorithme pour sortir du labyrinthe :\n";
    std::cout << "1. Algorithme de la main droite\n";
    std::cout << "2. Algorithme de Pledge\n";
    int choix;
    std::cin >> choix;

    if (choix == 1) {
        AlgoMainDroite algo(robot);
        algo.executer();
    } else if (choix == 2) {
        AlgoPledge algo(robot);
        algo.executer();
    } else {
        std::cout << "Choix invalide.\n";
    }

    return 0;
}
