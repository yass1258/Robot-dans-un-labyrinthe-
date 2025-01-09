#include "Deplacement.h"
#include "Constantes.h"
Deplacement::Deplacement(Robot& robot) : robot(robot) {}

void Deplacement::avancer() {

     int nouvelleLigne = robot.obtenirPosition().getX();
    int nouvelleColonne = robot.obtenirPosition().getY();

    // Calculer la nouvelle position
    switch (robot.getDirection()) {
        case HAUT:
            nouvelleLigne -= 1;
            break;
        case DROITE:
            nouvelleColonne += 1;
            break;
        case BAS:
            nouvelleLigne += 1;
            break;
        case GAUCHE:
            nouvelleColonne -= 1;
            break;
    }

    // Vérifie si la case devant est la case d'arrivée
    if (robot.obtenirTerrain().obtenirCase(nouvelleLigne, nouvelleColonne) == ARRIVEE) {
        std::cout << "Le robot est juste avant la case d'arrivée. Arrêt.\n";
        return; // Stoppe le déplacement
    }

    // Vérifie si le mouvement est valide
    if (nouvelleLigne >= 0 && nouvelleLigne < robot.obtenirTerrain().getLignes() &&
        nouvelleColonne >= 0 && nouvelleColonne < robot.obtenirTerrain().getColonnes() &&
        robot.obtenirTerrain().obtenirCase(nouvelleLigne, nouvelleColonne) != MUR) {

        // Efface l'ancienne position
        robot.obtenirTerrain().modifierCase(robot.obtenirPosition().getX(), robot.obtenirPosition().getY(), VIDE);

        // Met à jour la position
        robot.setPosition(nouvelleLigne, nouvelleColonne);

        // Met à jour la grille avec le robot
        robot.obtenirTerrain().modifierCase(nouvelleLigne, nouvelleColonne, ROBOT);
    } else {
        std::cout << "Mouvement bloqué par un mur ou hors limites.\n";
    }
}

void Deplacement::tournerDroite() {
    robot.setDirection(static_cast<Direction>((robot.getDirection() + 1) % 4));
}

void Deplacement::tournerGauche() {
    robot.setDirection(static_cast<Direction>((robot.getDirection() + 3) % 4));
}

bool Deplacement::devantMur() const {
    return caseDevant() == 'X';
}

char Deplacement::caseDevant() const {
    switch (robot.getDirection()) {
        case HAUT:
            return robot.obtenirTerrain().obtenirCase(robot.obtenirPosition().getX() - 1, robot.obtenirPosition().getY());
        case DROITE:
            return robot.obtenirTerrain().obtenirCase(robot.obtenirPosition().getX(), robot.obtenirPosition().getY() + 1);
        case BAS:
            return robot.obtenirTerrain().obtenirCase(robot.obtenirPosition().getX() + 1, robot.obtenirPosition().getY());
        case GAUCHE:
            return robot.obtenirTerrain().obtenirCase(robot.obtenirPosition().getX(), robot.obtenirPosition().getY() - 1);
    }
    return ' '; // Valeur par défaut
}
