#include <iostream>
#include "Terrain.h"
#include "Robot.h"
#include "AlgoMainDroite.h"
#include "AlgoPledge.h"

int main() {
    Terrain terrain;
    std::string nomFichier;

    // Demander � l'utilisateur de choisir un algorithme
    std::cout << "Choisissez un algorithme pour sortir du labyrinthe :\n";
    std::cout << "1. Algorithme de la main droite\n";
    std::cout << "2. Algorithme de Pledge\n";
    int choix;
    std::cin >> choix;

    // Charger le fichier correspondant
    if (choix == 1) {
        nomFichier = "labyrinthe.txt";
    } else if (choix == 2) {
        nomFichier = "labyrinthe2.txt";
    } else {
        std::cerr << "Choix invalide. Fin du programme.\n";
        return 1;
    }

    // Importer le labyrinthe
    terrain.importerDepuisFichier(nomFichier);
    std::cout << "Labyrinthe import� depuis " << nomFichier << " :\n";
    terrain.afficher();

    // Positionner le robot sur la case (1, 1)
    Position positionDepart(1, 1);
    Robot robot(terrain, positionDepart, DROITE);

    std::cout << "Robot initialis� � la position : ("
              << positionDepart.getX() << ", "
              << positionDepart.getY() << ") direction : DROITE\n";

    // Affichage initial avec le robot
    terrain.afficher(&robot);

    // Ex�cuter l'algorithme choisi
    if (choix == 1) {
        std::cout << "Ex�cution de l'algorithme de la main droite...\n";
        AlgoMainDroite algo(robot);
        algo.executer();
    } else if (choix == 2) {
        std::cout << "Ex�cution de l'algorithme de Pledge...\n";
        AlgoPledge algo(robot);
        algo.executer();
    }

    return 0;
}
